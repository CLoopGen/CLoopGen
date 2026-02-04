#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int pos;
int current_board[400];
int cached_board;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? (i % 4) : 0;
    }
    for (int i = 0; i < 400; i++) {
        current_board[i] = (i % 4 + 1) % 4;
    }
    pos = 0;
    cached_board = 1;
}