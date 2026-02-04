#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern unsigned int zobrist[14][144];
extern unsigned int hash;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = 0; p < 144; p++) {
    int val = board[p];
    if (!(val == 13 || val == 0)) {
        hash = hash ^ zobrist[val][p];
    }
}
}
