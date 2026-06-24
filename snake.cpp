#include <iostream>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <ctime>
#include <algorithm>
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 20;
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }
};
class SnakeGame {
private:
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Direction dir;
    bool gameOver;
    int score;
    int highScore;
    Point food;
    deque<Point> snake;
    char board[HEIGHT][WIDTH];
    void Setup() {
    gameOver = false;
    dir = STOP;
    snake.clear();  
    int startX = WIDTH / 2;
    int startY = HEIGHT / 2; 
    snake.push_front(Point(startX, startY));        // Head
    snake.push_back(Point(startX - 1, startY));     // Body
    snake.push_back(Point(startX - 2, startY));     // Tail
    score = 0;
    GenerateFood();
}
    void DrawBoard() {
        system("cls");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                    board[i][j] = '#';
                else
                    board[i][j] = ' ';
            }
        }
        for (const auto& p : snake)
            board[p.y][p.x] = 'O';

        board[snake.front().y][snake.front().x] = '@';
        board[food.y][food.x] = 'F';

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j)
                cout << board[i][j];
            cout << endl;
        }
        cout << "Score: " << score << " | High Score: " << highScore << endl;
    }
    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
            }
        }
    }
    void Logic() {
        Point newHead = snake.front();
        switch (dir) {
        case LEFT: newHead.x--; break;
        case RIGHT: newHead.x++; break;
        case UP: newHead.y--; break;
        case DOWN: newHead.y++; break;
        default: return;
        }
        if (newHead.x < 1 || newHead.x >= WIDTH - 1 || newHead.y < 1 || newHead.y >= HEIGHT - 1)
            gameOver = true;

        for (size_t i = 1; i < snake.size(); ++i)
            if (newHead == snake[i])
                gameOver = true;

        snake.push_front(newHead);

        if (newHead == food) {
            score++;
            GenerateFood();
        }
        else {
            snake.pop_back();
        }

        highScore = max(highScore, score);
    }
    void GenerateFood() {
        do {
            food.x = rand() % (WIDTH - 2) + 1;
            food.y = rand() % (HEIGHT - 2) + 1;
        } while (find(snake.begin(), snake.end(), food) != snake.end());
    }
public:
    SnakeGame() : highScore(0) {
        srand(static_cast<unsigned>(time(0)));
    }
    void Run() {
        while (true) {
            Setup();
            while (!gameOver) {
                DrawBoard();
                Input();
                Logic();
                Sleep(100);
            }
            cout << "Game Over! Your score: " << score << endl;
            cout << "Press 'r' to restart or 'q' to quit." << endl;
            char choice;
            do {
                choice = _getch();
            } while (choice != 'r' && choice != 'q');
            if (choice == 'q') break;
        }
    }
};
int main() {
    SnakeGame game;
    game.Run();
    return 0;
}