#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern ptrdiff_t stride;
extern unsigned int rlen;
extern unsigned int j;
extern unsigned int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using a separate index array
    unsigned int idx[rlen];
    int16_t *d = dst;
    // Precompute indirect indices based on current j, width, and stride pattern
    for (k = 0; k < rlen; k++) {
        unsigned int pos = j + k;
        idx[k] = pos % width;
        if (idx[k] == pos) { // No wrap-around
            d = dst + (pos / width) * (stride / sizeof(int16_t));
        }
    }
    // Perform strided zero assignment using computed indices
    for (k = 0; k < rlen; k++) {
        unsigned int linear_offset = (j + k) / width;
        d = dst + linear_offset * (stride / sizeof(int16_t));
        d[idx[k]] = 0;
    }
    // Update shared state
    j = (j + rlen) % width;
    dst += (rlen / width) * stride;
}
