#include <stdio.h>
#include <stdlib.h>
#include "sudom.h"

int main(int argc, char **argv) {
  SUDOKU s = create_sudoku();
  print_sudoku(s);
  free_sudoku(s);
}
