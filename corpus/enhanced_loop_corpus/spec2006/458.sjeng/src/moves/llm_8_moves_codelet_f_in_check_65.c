#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and higher trip count
    for (l = bking_loc + 22; board[l] == 13 && (l - bking_loc) < 121; l += 11) {
        l += (l % 13) ? 0 : 1;  // Extra conditional arithmetic to increase computation per iteration
    }
}
