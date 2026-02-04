#include <stdio.h>
#include <inttypes.h>

int board[144];
int square;
int king_o[8] = { -13, -12, -11, -1, 1, 11, 12, 13 };
int d;
int m;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 0;
    }
    square = 64;
    for (int i = 0; i < 8; i++) {
        int offset = king_o[i];
        int target = square + offset;
        if (target >= 0 && target < 144) {
            if ((i % 2) == 0) {
                board[target] = 13;
            }
        }
    }
    m = 0;
}