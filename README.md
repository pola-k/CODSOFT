# CODSOFT Internship C++ Projects

This repository contains four C++ projects developed during my internship with CODSOFT. Each project demonstrates various programming concepts and problem-solving techniques, ranging from basic operations like calculations to game development and task management systems. Below are brief descriptions of each project:

## Projects

### 1. Calculator
A simple console-based calculator that allows users to perform basic arithmetic operations (addition, subtraction, multiplication, and division). The program validates user inputs and handles invalid operations such as division by zero.

**Features:**
- Supports `+`, `-`, `*`, and `/` operations.
- Input validation to ensure the user enters valid numbers and operations.
- Continuous calculations until the user chooses to exit.

### 2. Guessing Game
A random number guessing game where the program generates a random number, and the user tries to guess it. The game provides hints on whether the guess is too high or too low, and it continues until the correct number is guessed.

**Features:**
- Generates a random number for each game session.
- Provides feedback on whether the user’s guess is too high or too low.
- Allows the user to continue playing until they guess correctly.

### 3. Tic-Tac-Toe
A two-player console-based Tic-Tac-Toe game. Players take turns selecting rows and columns to place their markers (`X` and `O`) on the game board. The game detects wins or draws and allows for replay.

**Features:**
- Validates player input to ensure they select an available spot.
- Detects when a player wins (3 markers in a row, column, or diagonal).
- Includes a replay option after the game ends.

### 4. To-Do List Manager
A task management system where users can add, remove, and mark tasks as complete. The program displays the tasks with their status (completed or pending) and supports updating and deleting tasks.

**Features:**
- Add tasks with automatic numbering.
- Mark tasks as completed.
- Remove tasks and adjust numbering accordingly.
- View all tasks with their status (pending/completed).

## How to Compile and Run
Each project is self-contained in its respective C++ file. You can compile and run them using a C++ compiler, such as g++ or any IDE like Visual Studio or Code::Blocks.

For example, to compile and run the Calculator program:
```bash
g++ -o calculator calculator.cpp
./calculator
```

## Requirements
- A C++ compiler (g++, Clang, or any compatible IDE).
- Basic knowledge of using a terminal or command prompt to compile and execute C++ files.

---
