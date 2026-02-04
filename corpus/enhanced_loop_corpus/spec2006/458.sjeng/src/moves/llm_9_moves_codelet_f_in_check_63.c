#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by skipping every other element, but increase per-iteration work
    int step = 13;
    for (l = bking_loc + step; board[l] == 13 && (l - bking_loc) < 104; l += step * 2) {
        // Double the step logically, limiting total iterations
        if (board[l + step] != 13) break;
    }
}
