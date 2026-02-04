#include <inttypes.h>

int board[144];
int bking_loc;
int l;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    bking_loc = 143;
    board[bking_loc] = 14;
    l = bking_loc;
}