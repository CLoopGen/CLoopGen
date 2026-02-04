#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using an offset array index (simulating sliding window)
    int start = (square - 12 > 0) ? square - 12 : 0; // Start from nearby region
    for (l = start; l < square && board[l] == 13; l++) {
        m++;
    }
}
