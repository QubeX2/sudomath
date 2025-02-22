#include <stdio.h>
#include <stdlib.h>
#include "sudom.h"

/**
* create_table
*/
SUDOKU* create_sudoku() {
  SUDOKU* s = malloc(sizeof(SUDOKU));
  s->table = malloc(sizeof(int *) * 9);
  s->options = malloc(sizeof(int **) * 9);
  for(int i = 0; i < 9; i++) {
    s->table[i] = malloc(sizeof(int) * 9);
    s->options[i] = malloc(sizeof(int*) * 9);
    for(int j = 0; j < 9; j++) {
      s->options[i][j] = malloc(sizeof(int) * 9);
    }
  }
  return s;
}

/**
* init table
*/
void init_sudoku(SUDOKU* s) {
  // init
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      s->table[i][j] = 0;
      for(int k = 0; k < 9; k++) {
        s->options[i][j][k] = k + 1;
      }
    }
  }

  // algorithm
}

/**
* free table
*/
void free_sudoku(SUDOKU* s) {
  if(s != NULL) {
    free(s->options);
    free(s->table);
    free(s);
  }
}
