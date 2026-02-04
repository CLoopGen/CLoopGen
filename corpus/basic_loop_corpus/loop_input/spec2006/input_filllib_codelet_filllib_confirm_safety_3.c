#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = {1, -1, 42, -42, 2, -2, 21, -21};

Intersection board[421];

int move;
int color;
int k;
int apos;

void init_vars() {
    move = 200;
    color = 1;
    k = 0;
    apos = -1;

    for (int i = 0; i < 421; i++) {
        board[i] = 0;
    }

    for (int d = 4; d < 8; d++) {
        int pos = move + delta[d];
        if (pos >= 0 && pos < 421) {
            board[pos] = 1;
            break;
        }
    }
}