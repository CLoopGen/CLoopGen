#include <stdio.h>
#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 13;
    }
    wking_loc = 110;
    int index = wking_loc;
    while (index >= 11) {
        index -= 11;
    }
    board[index] = 1; // Ensures loop termination when reaching this cell
    index = wking_loc;
    while (index >= 11) {
        index -= 11;
        if (index < 144) {
            board[index] = 13;
        }
    }
    board[wking_loc] = 13;
}