#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Unrolling (2x)
    // Instead of strided writes to v[i*2] and v[i*2+1], write consecutively using temporary variables
    // This improves spatial locality in stores to array v.
    int j = 0;
    for (i = 0; i < 16 - 2; i++) {
        uint8_t val1 = (left[i] + left[i + 1] + 1) >> 1;
        uint8_t val2 = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        v[j++] = val1;
        v[j++] = val2;
    }
}
