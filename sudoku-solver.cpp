#include <iostream>
#include <vector>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a number can be placed in a specific position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is already in the current row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if the number is already in the current column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if the number is already in the current 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N], int row, int col) {
    // If we have reached the last cell, the Sudoku is solved
    if (row == N - 1 && col == N) {
        return true;
    }

    // Move to the next row if we have reached the end of the current row
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip the filled cells
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try placing numbers from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively try to fill the rest of the grid
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }

            // Backtrack if the current number doesn't lead to a solution
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[N][N] = {
        {5, 2, 0, 0, 8, 0, 0, 7, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 3, 5, 2, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 1, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        std::cout << "No solution exists for the given Sudoku puzzle." << std::endl;
    }

    return 0;
}
