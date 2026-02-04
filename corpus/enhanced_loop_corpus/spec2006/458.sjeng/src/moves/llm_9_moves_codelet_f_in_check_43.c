#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count and simplified condition
    // Step by 1 instead of 11, increasing iterations significantly, but guard with a range check to stay safe.
    // Remove complex conditions; only perform minimal checks. This simulates a linear scan.
    int upper_bound = bking_loc + 121;  // Assume maximum reasonable bound on board
    for (l = bking_loc + 11; l < upper_bound && board[l] == 13; l++) {
        // Empty body – all work done in loop header
    }
}
