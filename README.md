# Snake_game
A classic Snake game built in C++ for the console. It features smooth movement using deque, collision detection for walls and body segments, a random food spawning system, and a high-score tracker. Perfect for learning game loops and basic coordinate-based mechanics.

# 🐍 Console Snake Game in C++

Welcome to the classic, terminal-based **Snake Game** built in pure C++! This project leverages lightweight, low-level console rendering and native Windows APIs to deliver a smooth, high-performance retro gaming experience directly inside your command line window. 🎮

---

## 🚀 Features & Implementation

* **Dynamic Body Tracking:** Utilizes a double-ended queue (`std::deque<Point>`) to manage the snake's coordinates. This ensures highly efficient **O(1)** execution time when adding segments to the head and popping them from the tail.
* **Asynchronous Input Engine:** Captures real-time keyboard strokes smoothly using Windows-native `_kbhit()` and `_getch()` utilities, preventing the core game loop from lagging or waiting for input.
* **Matrix Buffer Rendering:** Dynamically instantiates a 2D `char` matrix to clear and draw borders (`#`), the snake head (`@`), body parts (`O`), and fruit targets (`F`) inside a fixed layout.
* **Local State Persistency:** Tracks real-time active gaming scores, actively evaluates high-score boundaries, and offers instant session reloading upon triggering a collision.

---

## 🕹️ Game Mechanics

1. **The Grid:** The playground is bounded by an immutable wall system. Touching the boundary results in an immediate game over.
2. **Growth Loop:** Every time the snake head coordinates overlap with a food item (`F`), the score increases, a new food coordinate is randomly generated, and the tail-end deletion is skipped to grow the length.
3. **Speed Config:** The game tick runs on a baseline 100ms hardware delay loop (`Sleep(100)`), balancing real-time difficulty and standard console rendering refresh limits.

---

## 🎮 Controls

Use the classic WASD layout to guide your snake across the console board:

| Key | Action |
| :---: | :--- |
| **W** | 🔼 Move Up |
| **S** | 🔽 Move Down |
| **A** | ◀️ Move Left |
| **D** | ▶️ Move Right |
| **X** | 🛑 Forfeit / Stop Match |
| **R** | 🔄 Restart Game (On Game Over Screen) |
| **Q** | 🚪 Quit Application (On Game Over Screen) |

---

## 🛠️ Prerequisites

Before compiling, verify that your local computer setup fulfills the following environment requirements:
* **Operating System:** Microsoft Windows (strictly required due to native `<windows.h>` and `<conio.h>` dependencies).
* **Compiler Toolchain:** GCC/MinGW or MSVC standalone tools supporting C++11 or later standards.

---

## 💻 How to Build and Run

Follow these quick command-line instructions to compile and play the game:

1. Open your **Command Prompt** or **PowerShell** window in the directory containing your project source files.
2. Execute the compiler to generate the binary executable:
   ```bash
   g++ -o snake_game main.cpp

## Run the executable
       snake_game.exe




    
