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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing b[2*x] and b[2*x+1], we process two elements consecutively in a coalesced manner.
    // Also restructure tmp access to maintain data dependency but improve spatial locality.
    int limit = w2;
    for (x = 0; x < limit; x++) {
        int val = tmp[x];
        b[2 * x] = ((int)(val + 1U)) >> 1;

        int offset_b = x + w2;
        int sum_tmp = 9U * val + 9U * tmp[x + 1] - tmp[x + 2] - tmp[x - 1] + 8;
        int filtered = (int)(((unsigned int)(b[offset_b]) + ((int)(sum_tmp >> 4))) + 1U) >> 1;
        b[2 * x + 1] = filtered;
    }
}
