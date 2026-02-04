#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int32_t *b;
extern int32_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Loop Unrolling (factor of 2)
    // Instead of accessing b[2*x] and b[2*x+1], we process two elements at a time consecutively in output.
    // Also restructure access to tmp and b for better spatial locality.

    int limit = w2 - (w2 % 2); // Ensure even bound for unrolling
    for (x = 0; x < limit; x += 2) {
        // Process two iterations worth of data, writing 4 consecutive outputs in b
        int val1 = ((int)(tmp[x] + 1U)) >> 1;
        int val2 = ((int)(tmp[x + 1] + 1U)) >> 1;

        b[2 * x]     = val1;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;

        b[2 * x + 2] = val2;
        b[2 * x + 3] = ((int)((int)(((unsigned int)(b[x + 1 + w2]) + ((int)(9U * tmp[x + 1] + 9U * tmp[x + 2] - tmp[x + 3] - tmp[x] + 8) >> 4))) + 1U)) >> 1;
    }

    // Handle remaining element if w2 is odd
    if (x < w2) {
        b[2 * x] = ((int)(tmp[x] + 1U)) >> 1;
        b[2 * x + 1] = ((int)((int)(((unsigned int)(b[x + w2]) + ((int)(9U * tmp[x] + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8) >> 4))) + 1U)) >> 1;
    }
}
