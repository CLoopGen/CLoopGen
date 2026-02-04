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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing elements in a strided and reversed manner,
    // reorganize the loop to traverse low and high arrays with consecutive indices.
    // We simulate the same logical behavior but using forward, consecutive access.
    int idx = *i;
    for (; idx >= 0; idx -= 2) {
        int src_idx = idx >> 1;
        low[idx]     = low[src_idx];
        low[idx + 1] = high[src_idx];
    }
    *i = idx;
}
