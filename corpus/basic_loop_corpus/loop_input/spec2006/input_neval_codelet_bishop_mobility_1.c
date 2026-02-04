#include <stdio.h>
#include <inttypes.h>

int board[144];
int square;
int l;
int m;
int diridx;
int dir[4];

void init_vars() {
    square = 72;
    m = 0;
    dir[0] = 1;
    dir[1] = 12;
    dir[2] = -1;
    dir[3] = -12;

    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }

    board[square] = 0;
}