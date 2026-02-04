#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc + 12; board[l] == 13 && l < 144; l += 24) {
        // Increased step size reduces trip count by ~50%
        // Simulates coarser traversal with fewer iterations
        int offset = l % 12;
        offset *= 2; // Additional arithmetic to maintain body complexity
    }
}
