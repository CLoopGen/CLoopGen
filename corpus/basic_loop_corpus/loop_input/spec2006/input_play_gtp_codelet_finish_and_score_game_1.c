#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 19;
Intersection board[421];
int i;
int j;
int current_board[19][19];
int cached_board;

void init_vars() {
    for (int idx = 0; idx < 421; ++idx) {
        board[idx] = (unsigned char)(idx % 256);
    }
    for (int ii = 0; ii < 19; ++ii) {
        for (int jj = 0; jj < 19; ++jj) {
            current_board[ii][jj] = (ii * 19 + jj) % 100;
        }
    }
    cached_board = 1;
}