#include <stdio.h>
#include <stdlib.h>
#include "sudom.h"

int main(int argc, char **argv) {
  SUDOKU* s = create_sudoku();
  init_sudoku(s);

  printf("%d, %d\n", s->table[0][0], s->options[0][0][0]);
  free_sudoku(s);
}
