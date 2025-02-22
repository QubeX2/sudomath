
#ifndef SUDOM_H
#define SUDOM_H

struct Sudoku {
  int** table;
  int*** options;
};

typedef struct Sudoku SUDOKU;

SUDOKU* create_sudoku();
void free_sudoku(SUDOKU* s);
void init_sudoku(SUDOKU* s);

#endif
