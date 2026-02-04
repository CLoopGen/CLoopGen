#include <stdio.h>
#include <inttypes.h>

int board[144];
int square;
int bishop_o[4];
int a_sq;
int i;
int attackers;

void init_vars() {
    square = 64;
    bishop_o[0] = 13;
    bishop_o[1] = 11;
    bishop_o[2] = -13;
    bishop_o[3] = -11;

    for (int idx = 0; idx < 144; idx++) {
        board[idx] = 0;
    }

    board[square + bishop_o[0]] = 0;
    board[square + bishop_o[1]] = 5;
    board[square + bishop_o[2]] = 0;
    board[square + bishop_o[3]] = 0;

    attackers = 0;
}