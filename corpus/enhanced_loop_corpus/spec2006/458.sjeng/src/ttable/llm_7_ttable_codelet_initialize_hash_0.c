#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int p = 0; p < 144; p += 2) {
        int idx1 = p;
        int idx2 = p + 1;
        unsigned int val1 = 0, val2 = 0;
        if (idx1 < 144 && board[idx1] != 13 && board[idx1] != 0)
            val1 = zobrist[board[idx1]][idx1];
        if (idx2 < 144 && board[idx2] != 13 && board[idx2] != 0)
            val2 = zobrist[board[idx2]][idx2];
        hash = hash ^ val1 ^ val2;
    }
}
