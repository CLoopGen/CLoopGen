#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int p;
for (p = 0; p < 72; p++) {
    int idx1 = 2 * p;
    int idx2 = 2 * p + 1;
    if (board[idx1] != 13 && board[idx1] != 0)
        hash = hash ^ zobrist[board[idx1]][idx1];
    if (board[idx2] != 13 && board[idx2] != 0)
        hash = hash ^ zobrist[board[idx2]][idx2];
}
}
