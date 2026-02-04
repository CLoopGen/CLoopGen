#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int ii;
int cached_board[400];
int board_was_cached;

void init_vars() {
    board_was_cached = 1;
    for (int i = 0; i < 400; i++) {
        board[i] = i % 256;
        cached_board[i] = (i + 1) % 256;
    }
    for (int i = 400; i < 421; i++) {
        board[i] = i % 256;
    }
}