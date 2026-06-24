# Snake_game
A classic Snake game built in C++ for the console. It features smooth movement using deque, collision detection for walls and body segments, a random food spawning system, and a high-score tracker. Perfect for learning game loops and basic coordinate-based mechanics.

# Console Snake Game in C++

A classic, terminal-based Snake Game implemented in C++. This project utilizes standard data structures and native Windows APIs to deliver a smooth retro gaming experience right in your command line interface.

---

## Features & Implementation

* **Dynamic Body Tracking:** Uses `std::deque<Point>` for highly efficient $O(1)$ body insertions and trailing deletions.
* **Asynchronous Input:** Captures real-time keyboard inputs via `_kbhit()` and `_getch()` without freezing the game loop.
* **Matrix Rendering:** Dynamically draws borders (`#`), snake head (`@`), body (`O`), and food (`F`) on a 20x20 grid layout.
* **State Persistency:** Tracks current score, updates high scores locally, and provides an instant restart option on game over.

---

## Controls

| Key | Action |
| :--- | :--- |
| **W** | Move Up |
| **S** | Move Down |
| **A** | Move Left |
| **D** | Move Right |
| **X** | Forfeit Match |
| **R** | Restart (On Game Over Screen) |
| **Q** | Quit (On Game Over Screen) |

---

## Prerequisites

* **OS:** Windows (relies on `<windows.h>` and `<conio.h>`)
* **Compiler:** GCC/MinGW or MSVC supporting C++11 or later

---

## How to Build and Run

1. Open your Command Prompt or PowerShell in the project directory.
2. Compile the source file:
   ```bash
   g++ -o snake_game main.cpp

## Run the executable
    snake_game.exe




    
