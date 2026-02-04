#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = 0;
    const int max_steps = 8;
    for (int i = 1; i <= max_steps; ++i) {
        offset += 12;
        l = bking_loc - offset;
        if (board[l] != 13) break;
    }
}
