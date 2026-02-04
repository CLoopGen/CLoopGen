#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access by -13, simulate same logic using consecutive indices
    // Map original l = square - 13, then l -= 13 to a consecutive index i
    int base = (square - 13) % 13;
    for (int i = (square - 13) / 13; i >= 0 && board[base + i * 13] == 13; i--)
        m++;
}
