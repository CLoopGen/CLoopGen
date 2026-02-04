#include <stdint.h>
#include <string.h>

int board[144];
int square = 64;
int bishop_o[4] = { -13, -11, 11, 13 };
int a_sq;
int i;
int attackers;

void init_vars() {
    memset(board, 0, sizeof(board));
    
    square = 64;
    bishop_o[0] = -13; bishop_o[1] = -11;
    bishop_o[2] = 11; bishop_o[3] = 13;
    
    a_sq = 0;
    i = 0;
    attackers = 0;

    board[64 + (-13)] = 13;
    board[64 + (-11)] = 6;
    board[64 + 11] = 0;
    board[64 + 13] = 0;

    int temp = 64 + bishop_o[0];
    while (temp >= 0 && temp < 144) {
        if (board[temp] == 0) break;
        temp += bishop_o[0];
    }
}