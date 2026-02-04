#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int piece;
    int square;
} see_data;

int board[144];
see_data see_attackers[2][16];
int square;
int bishop_o[4];
int a_sq;
int b_sq;
int i;
int numw;
int numb;

void init_vars() {
    for (int idx = 0; idx < 144; idx++) {
        board[idx] = 0;
    }

    square = 50;
    bishop_o[0] = 13;
    bishop_o[1] = 11;
    bishop_o[2] = -11;
    bishop_o[3] = -13;

    a_sq = 0;
    b_sq = 0;
    i = 0;
    numw = 0;
    numb = 0;

    for (int idx = 0; idx < 2; idx++) {
        for (int j = 0; j < 16; j++) {
            see_attackers[idx][j].piece = 0;
            see_attackers[idx][j].square = 0;
        }
    }

    board[square + bishop_o[0]] = 13;
    board[square + bishop_o[0] + bishop_o[0]] = 11;

    board[square + bishop_o[1]] = 5;

    board[square + bishop_o[2]] = 6;

    board[square + bishop_o[3]] = 13;
    board[square + bishop_o[3] + bishop_o[3]] = 10;
}