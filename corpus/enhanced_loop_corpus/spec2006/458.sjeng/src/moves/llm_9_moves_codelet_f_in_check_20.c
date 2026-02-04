#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc + 24; board[l] == 13 && l < 144; l += 24) {
        // Stride doubled to reduce trip count and increase memory access spacing
        // Simulates coarser traversal with fewer iterations
    }
}
