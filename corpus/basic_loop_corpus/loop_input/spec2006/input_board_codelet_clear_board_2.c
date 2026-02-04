#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 19;
Intersection board[421];
Intersection initial_board[421];
int k;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = 0;
        initial_board[i] = 0;
    }
    k = 0;
}