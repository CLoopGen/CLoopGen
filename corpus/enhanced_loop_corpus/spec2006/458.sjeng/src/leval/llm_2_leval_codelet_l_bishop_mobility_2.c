#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access (+11), we use consecutive indices
    // We simulate the same condition by checking every element from a computed start point
    int start = (square + 11) % 144;
    for (l = start; l < 144 && board[l] == 13; l++)
        m++;
}
