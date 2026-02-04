#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int board_size = 19;
Intersection board[421];
int color = 2;
int m = 10;
int n = 10;
int merged_val = 0;
int i = 0;
int j = 0;
int shift = 0;

void init_vars() {
    board_size = 19;
    color = 2;
    m = 9;
    n = 9;
    merged_val = 0;
    i = 0;
    j = 0;
    shift = 30;

    for (int idx = 0; idx < 421; ++idx) {
        board[idx] = idx % 3;
    }
}