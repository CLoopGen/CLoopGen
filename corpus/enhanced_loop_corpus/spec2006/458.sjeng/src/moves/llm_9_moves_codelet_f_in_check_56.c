#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with conditional skip and added bit manipulation
    int step = 11;
    for (l = bking_loc + step; board[l] == 13; l += (step & (~((board[l + 5] >> 3) & 1)))) {
        step = 11 + ((l ^ bking_loc) & 1);  // Alternate step using XOR and bitwise AND
    }
}
