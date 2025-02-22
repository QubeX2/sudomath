#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudom.h"

/**
* create_table
*/
SUDOKU create_sudoku() {
  SUDOKU s = malloc(sizeof(int*) * 9);
  for(int i = 0; i < 9; i++) {
    s[i] = malloc(sizeof(int) * 9);
    for(int j = 0; j < 9; j++) {
      s[i][j] = 0;
    }
  }
  return s;
}

SUDOKU copy_sudoku(SUDOKU s) {
  SUDOKU t = create_sudoku();
  for(int r = 0; r < 9; r++) {
    for(int c = 0; c < 9; c++) {
      t[r][c] = s[r][c];
    }
  }
  return t;
}

/**
* init table
*/
void init_sudoku(SUDOKU s) {
  // algorithm
  srand(time(NULL));
  s[0][0] = rand() % 9 + 1;
  for(int i = 0; i < 8; i++) {
    int r = rand() % 9;
    int c = rand() % 9;
    int n = rand() % 9 + 1;
    if(is_safe(s, r, c, n)) {
      s[r][c] = n;
    }
  }

  solve_sudoku(s);
  SUDOKU t = copy_sudoku(s);
  while(solve_sudoku(t) && count_values(s) > 20) {
    printf("count := %d\n", count_values(t));
    int r = rand() % 9;
    int c = rand() % 9;
    s[r][c] = 0;
    free_sudoku(t);
    t = copy_sudoku(s);
    print_sudoku(s);
  }

  free_sudoku(s);
}

int count_values(SUDOKU s) {
  int count = 0;
  for(int r = 0; r < 9; r++) {
    for(int c = 0; c < 9; c++) {
      if(s[r][c] > 0) {
        count++;
      }
    }
  }
  return count;
}

bool solve_sudoku(SUDOKU s) {
  solve_sudoku_rec(s, 0, 0);
  for(int r = 0; r < 9; r++) {
    for(int c = 0; c < 9; c++) {
      if(s[r][c] == 0) {
        return false;
      }
    }
  }
  return true;
}

bool solve_sudoku_rec(SUDOKU s, int row, int col) {
  if(row == 8 && col == 9) {
    return true;
  }

  if(col == 9) {
    row++;
    col = 0;
  }

  if(s[row][col] != 0) {
    return solve_sudoku_rec(s, row, col + 1);
  }

  for(int n = 1; n <= 9; n++) {
    if(is_safe(s, row, col, n)) {
      s[row][col] = n;
      if(solve_sudoku_rec(s, row, col + 1)) {
        return true;
      }
      s[row][col] = 0;
    }
  }

  return false;
}

bool is_safe(SUDOKU s, int row, int col, int value) {
  for(int i = 0; i < 9; i++) {
    if(s[row][i] == value) {
      return false;
    }
    if(s[i][col] == value) {
      return false;
    }
  }

  int sr = row - (row % 3), sc = col - (col % 3);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(s[sr + i][sc + j] == value) {
        return false;
      }
    }
  }

  return true;
}

/**
 * print_sudoku
 */
void print_sudoku(SUDOKU s) {
  printf("     A B C   D E F   G H I\n");
  
  for(int r = 0; r < 9; r++) {
    if((r % 3) == 0) {
      printf("   +-----------------------+\n");
    }
    printf("%d:", (r + 1));
    for(int c = 0; c < 9; c++) {
      if((c % 3) == 0) {
        if(s[r][c] == 0)
          printf(" |  ");
        else
          printf(" | %d", s[r][c]);
      } else {
        if(s[r][c] == 0)
          printf("  ", s[r][c]);
        else 
          printf(" %d", s[r][c]);
      }
    }
    printf(" |\n");
  }
  printf("   +-----------------------+\n");
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
