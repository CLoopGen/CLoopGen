#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int p;
for (p = 0; p < 144; p += 3) {
    if (board[p] != 13 && board[p] != 0)
        hash = hash ^ zobrist[board[p]][p];
    if (p+1 < 144 && board[p+1] != 13 && board[p+1] != 0)
        hash = hash ^ zobrist[board[p+1]][p+1];
    if (p+2 < 144 && board[p+2] != 13 && board[p+2] != 0)
        hash = hash ^ zobrist[board[p+2]][p+2];
}
}
