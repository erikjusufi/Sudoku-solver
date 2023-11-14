# Sudoku Solver

A C++ program that solves Sudoku puzzles using a backtracking algorithm with prioritized empty cells.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Example](#example)

## Introduction

This Sudoku Solver is implemented in C++ and utilizes a backtracking algorithm to find a solution for a given Sudoku puzzle. The empty cells are prioritized based on the number of possible moves, making the solving process more efficient.

## Features

- Backtracking algorithm with priority queue for empty cells.
- Count of backtrace calls during the solving process.

## Getting Started

1. **Clone the repository:**

    ```bash
    git clone https://github.com/yourusername/sudoku-solver.git
    cd sudoku-solver
    ```

2. **Compile the program:**

    ```bash
    g++ -o sudoku_solver main.cpp
    ```

## Usage

To run the Sudoku Solver, execute the compiled program with a Sudoku puzzle as input.

```bash
./sudoku_solver
```
The program will output the final solution and the number of backtrace calls.

## Example

```bash
int puzzle[9][9] = {
        {5, 3, -1, -1, 7, -1, -1, -1, -1},
        {6, -1, -1, 1, 9, 5, -1, -1, -1},
        {-1, 9, 8, -1, -1, -1, -1, 6, -1},
        {8, -1, -1, -1, 6, -1, -1, -1, 3},
        {4, -1, -1, 8, -1, 3, -1, -1, 1},
        {7, -1, -1, -1, 2, -1, -1, -1, 6},
        {-1, 6, -1, -1, -1, -1, 2, 8, -1},
        {-1, -1, -1, 4, 1, 9, -1, -1, 5},
        {-1, -1, -1, -1, 8, -1, -1, 7, 9}
    };
```
Solution
![image](https://github.com/erikjusufi/sudoku_solver/assets/80853756/15240594-6cfc-4ba9-bc8b-c1ae2e511221)
