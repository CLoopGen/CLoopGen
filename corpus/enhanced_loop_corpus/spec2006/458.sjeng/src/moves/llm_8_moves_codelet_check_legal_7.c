#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled check
    for (l = bking_loc + 11; board[l] == 13 && board[l + 11] == 13 && (l - bking_loc - 11) < 121; l += 22) {
        if (board[l + 5] % 2 == 0) {
            l += 1;
        }
    }
}
