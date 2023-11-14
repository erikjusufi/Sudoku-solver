# Sudoku Solver

A C++ program that solves Sudoku puzzles using a backtracking algorithm with prioritized empty cells.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

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
The program will output the final solution and the number of backtrace calls.
