#include <stdbool.h>

#ifndef SUDOM_H
#define SUDOM_H

typedef int** SUDOKU;

SUDOKU create_sudoku();
SUDOKU copy_sudoku(SUDOKU s);
void init_sudoku(SUDOKU s);
void print_sudoku(SUDOKU s);
void free_sudoku(SUDOKU s);
bool is_safe(SUDOKU s, int row, int col, int value);
bool solve_sudoku_rec(SUDOKU s, int row, int col);
bool solve_sudoku(SUDOKU s);
int count_values(SUDOKU s);

#endif
