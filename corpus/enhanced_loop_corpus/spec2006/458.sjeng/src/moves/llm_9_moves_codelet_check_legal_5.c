#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride doubling, simulating early termination
    // Less computationally intensive per iteration but changes loop progression
    for (l = bking_loc + 13; board[l] == 13 && (l - bking_loc) < 104; l += 26)
        ;
}
