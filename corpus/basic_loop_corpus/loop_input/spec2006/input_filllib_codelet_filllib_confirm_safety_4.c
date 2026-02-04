#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = {1, -1, 4, -4, 2, -2, 8, -8};

Intersection board[421];

int move;
int color;
int k;
int apos;

void init_vars() {
    move = 100;
    color = 1;
    for (int i = 0; i < 421; ++i) {
        board[i] = 0;
    }
    for (int i = 0; i < 4; ++i) {
        int pos = move + 2 * delta[i];
        if (pos >= 0 && pos < 421) {
            board[pos] = (i == 3) ? color : 0;
        }
    }
}