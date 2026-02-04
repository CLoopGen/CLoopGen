#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int tmp[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Original array indices are reorganized to access tmp in sequential order
    // Instead of accessing 0+i, 8+i, 4+i, 12+i (strided), we process sequentially
    for (i = 0; i < 4; ++i) {
        const int a0;
        const int a1;
        const int a2;
        const int a3;
        // Reorder assignments to write consecutively: [0+i], [1+i], [2+i], [3+i]
        tmp[0 + i] = a0 + a1;
        tmp[1 + i] = a0 - a1;
        tmp[2 + i] = a3 + a2;
        tmp[3 + i] = a3 - a2;
    }
}
