#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }
    wking_loc = 143;
    board[wking_loc] = 0;
    int temp = wking_loc - 11;
    while (temp >= 0) {
        board[temp] = 0;
        temp -= 11;
    }
}