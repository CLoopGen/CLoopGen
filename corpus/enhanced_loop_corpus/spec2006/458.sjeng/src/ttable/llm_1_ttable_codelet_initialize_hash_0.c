#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 12; outer++) {
    for (p = outer * 12; p < (outer + 1) * 12 && p < 144; p++) {
        if (board[p] != 13 && board[p] != 0)
            hash = hash ^ zobrist[board[p]][p];
    }
}
}
