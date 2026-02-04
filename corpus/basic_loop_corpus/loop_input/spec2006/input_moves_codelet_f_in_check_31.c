#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    wking_loc = 0;
    l = 0;
}