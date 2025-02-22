#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudom.h"

/**
* create_table
*/
SUDOKU create_sudoku() {
  int** s = malloc(sizeof(int*) * 9);
  for(int i = 0; i < 9; i++) {
    s[i] = malloc(sizeof(int) * 9);
    for(int j = 0; j < 9; j++) {
      s[i][j] = 0;
    }
  }
  return s;
}

/**
* init table
*/
void init_sudoku(SUDOKU s) {
  // algorithm
  solve_sudoku(s);
}

void solve_sudoku(SUDOKU s) {
  
}

void solve_sudoku_rec(SUDOKU s, int row, int col) {

}

bool is_safe(SUDOKU s, int row, int col, int value) {

}

/**
 * print_sudoku
 */
void print_sudoku(SUDOKU s) {
  printf("   A B C D E F G H I\n");
  printf("  +-+-+-+-+-+-+-+-+-+\n");
  
  for(int r = 0; r < 9; r++) {
    printf("%d:", (r + 1));
    for(int c = 0; c < 9; c++) {
      printf("|%d", s[r][c]);
    }
    printf("|\n");
  }
  printf("  +-+-+-+-+-+-+-+-+-+\n");
}
/**
* free table
*/
void free_sudoku(SUDOKU s) {
  if(s != NULL) {
    for(int i = 0; i < 9; i++) {
      free(s[i]);
    }
    free(s);
  }
}
