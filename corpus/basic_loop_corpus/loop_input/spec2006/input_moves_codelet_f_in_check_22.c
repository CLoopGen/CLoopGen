#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    wking_loc = 0;
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    board[143] = 0;
}