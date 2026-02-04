#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 3
    for (p = 0; p < 144; p += 3) {
        int idx1 = p;
        int idx2 = p + 1;
        int idx3 = p + 2;

        if (idx1 < 144 && board[idx1] != 13 && board[idx1] != 0)
            hash = hash ^ zobrist[board[idx1]][idx1];
        if (idx2 < 144 && board[idx2] != 13 && board[idx2] != 0)
            hash = hash ^ zobrist[board[idx2]][idx2];
        if (idx3 < 144 && board[idx3] != 13 && board[idx3] != 0)
            hash = hash ^ zobrist[board[idx3]][idx3];
    }
}
