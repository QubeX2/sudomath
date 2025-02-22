#include <stdbool.h>

#ifndef SUDOM_H
#define SUDOM_H

typedef int** SUDOKU;

SUDOKU create_sudoku();
void init_sudoku(SUDOKU s);
void print_sudoku(SUDOKU s);
void free_sudoku(SUDOKU s);
bool is_safe(SUDOKU s, int row, int col, int value);
void solve_rec(SUDOKU s, int row, int col);
void solve(SUDOKU s);

#endif
