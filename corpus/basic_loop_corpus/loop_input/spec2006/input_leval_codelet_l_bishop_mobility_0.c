#include <inttypes.h>

int board[144];
int square;
int l;
int m;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    square = 143;
    l = 0;
    m = 0;
}