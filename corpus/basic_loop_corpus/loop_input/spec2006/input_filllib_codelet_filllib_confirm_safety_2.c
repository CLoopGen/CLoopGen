#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = {1, -1, 4, -4, 2, -2, 3, -3};

Intersection board[421];

int move;
int color;
int k;
int apos;

void init_vars() {
    move = 200;
    color = 1;
    k = 0;
    apos = 0;

    for (int i = 0; i < 421; ++i) {
        board[i] = 0;
    }

    for (int i = 0; i < 4; ++i) {
        int pos = move + delta[i];
        if (pos >= 0 && pos < 421) {
            board[pos] = (i == 2) ? color : 0;
        }
    }
}