# Sudoku Solver

## Project Description

This is a Sudoku Solver program developed in C++ as part of my internship at Prodigy Infotech. The program takes a partially filled Sudoku board as input and fills the board in a way that meets the requirements of a Sudoku puzzle.

## Features

- Solve any valid Sudoku puzzle.
- Implemented using backtracking algorithm.
- Provides solution in a visually understandable format.

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC)
- A development environment or text editor (Visual Studio Code, CLion, etc.)

### Installing

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/divyan7982/PRODIGY_SD_04.git
    ```

2. **Navigate to the Project Directory:**

    ```bash
    cd PRODIGY_SD_04
    ```

### Running the Program

1. **Compile the C++ Source Code:**

    ```bash
    g++ sudoku_solver.cpp -o sudoku_solver
    ```

2. **Run the Executable:**

    ```bash
    ./sudoku_solver
    ```

## Usage

- The program prompts you to enter a 9x9 Sudoku grid.
- Enter the grid row by row, using 0 to represent empty cells.
- The program will print the solved Sudoku grid if a solution is found.
