#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access by 12, we simulate equivalent logic using a consecutive index
    // and map it to the original stride via arithmetic. This maintains the same effective access pattern
    // but expresses it differently for potential vectorization or cache optimization.
    int base = (square + 12) / 12 * 12; // Align to nearest multiple of 12
    for (int idx = 0; board[base + idx * 12] == 13; idx++) {
        m++;
        if (base + (idx + 1) * 12 >= 144) break; // Safety bound check
    }
}
