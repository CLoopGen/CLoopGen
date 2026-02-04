#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with nested loop introducing memory access pattern variation
    for (i = 0; i <= 63; i++) {
        ssize_t base = i << 2;  // Multiply by 4
        extrema[base] = 0;
        extrema[base + 1] = 0;
        extrema[base + 2] = 0;
        extrema[base + 3] = 0;
    }
}
