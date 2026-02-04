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
    // Variant 2: Strided Memory Access with Offset Decoupling
    // Modify access pattern to use a fixed stride and decouple index computation
    // by precomputing effective addresses with consistent step patterns.
    // This increases stride in memory accesses while preserving correctness.
    int step = 2;
    int idx = (*i) & (~1); // Ensure even starting point
    for (; idx >= 0; idx -= step) {
        int half_idx = idx >> 1;
        IDWTELEM temp_low = low[half_idx];
        IDWTELEM temp_high = high[half_idx];
        low[idx + 1] = temp_high;
        low[idx]     = temp_low;
    }
    *i = idx;
}
