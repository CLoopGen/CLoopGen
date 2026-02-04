#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = 0; p < 144; p++) {
    if (board[p] == 13 || board[p] == 0)
        continue;
    hash = hash ^ zobrist[board[p]][p];
}
}
