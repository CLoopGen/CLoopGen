#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l;
    for (prev_l = wking_loc - 1; board[prev_l] == 13; prev_l--) {
        l = prev_l;  // Introduce RAW dependency: l read after write from previous iteration
    }
    l = prev_l;  // Final update to maintain correctness
}
