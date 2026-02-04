#include <inttypes.h>

int board[144];
int king_o[8];
int square;
int d;
int m;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 0;
    }
    for (int i = 0; i < 8; i++) {
        king_o[i] = (i * 17) % 23 - 11;
    }
    square = 64;
    m = 0;
}