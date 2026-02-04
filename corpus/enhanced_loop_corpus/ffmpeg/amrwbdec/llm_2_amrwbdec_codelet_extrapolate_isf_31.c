#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of accessing isf[i] and isf[i-1], we shift the base index to enable consecutive writes
    // We process the same logical range but adjust indexing to promote cache locality
    int start_idx = 16;
    for (i = start_idx; i < 19; i++) {
        int idx = i - start_idx; // j equivalent
        isf[i] = isf[i - 1] + diff_isf[idx] * (1.F / (1 << 15));
    }
}
