#include <stdint.h>

int board[144];
int square;
int rook_o[4];
int a_sq;
int i;
int attackers;

void init_vars() {
    square = 64;
    rook_o[0] = 1;
    rook_o[1] = -1;
    rook_o[2] = 12;
    rook_o[3] = -12;
    attackers = 0;

    for (int idx = 0; idx < 144; idx++) {
        board[idx] = 0;
    }

    board[square + rook_o[0] + rook_o[0]] = 7;
    board[square + rook_o[1]] = 13;
    board[square + rook_o[1] + rook_o[1]] = 9;
    board[square + rook_o[2]] = 5;
}