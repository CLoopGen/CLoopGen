#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int *i;
extern IDWTELEM *low;
extern IDWTELEM *high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of accessing elements in a strided manner, we process two consecutive outputs per iteration
    // using a derived index to ensure coalesced writes to 'low' array.
    int idx = (*i) + 1;
    for (; idx >= 1; idx -= 2) {
        int src_idx = idx >> 1;
        low[idx]     = high[src_idx];
        low[idx - 1] = low[src_idx];
    }
}
