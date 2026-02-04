#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access by 13, use consecutive indices but map them through a formula
    int base = square + 13;
    for (l = 0; board[base + l * 13] == 13; l++)
        m++;
}
