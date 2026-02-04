#include <stdio.h>
#include <inttypes.h>

int board[144];
unsigned int zobrist[14][144];
unsigned int hash;
int p;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = i % 14;
    }
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 144; j++) {
            zobrist[i][j] = (unsigned int)(i * 144 + j);
        }
    }
    hash = 0;
    p = 0;
}