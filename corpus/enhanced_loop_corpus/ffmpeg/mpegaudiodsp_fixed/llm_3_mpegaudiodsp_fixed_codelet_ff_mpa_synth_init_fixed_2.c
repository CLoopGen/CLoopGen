#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Transform into a single loop with strided access to increase stride on both source and destination
    int idx;
    for (idx = 0; idx < 128; idx++) {
        i = idx / 16;  // Recover i
        j = idx % 16;  // Recover j
        // Use strided access pattern: write every 16th element in chunks
        window[640 + idx] = window[64 * i + 48 - j];  // Contiguous output, strided input via arithmetic
    }
}
