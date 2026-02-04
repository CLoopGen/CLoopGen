#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled filtering
    // Instead of strided access, we precompute a temporary array for filtered values
    // and write to dst in consecutive fashion. Also, we process two elements at a time.

    for (y = 0; y < height; y++) {
        int16_t temp[64];  // Temporary buffer to hold computed values
        for (x = 0; x < width - 1; x += 2) {
            // Unroll two iterations and compute using direct indexing
            temp[x]     = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
            temp[x + 1] = (filter[0] * src[x] + filter[1] * src[x + 1] + filter[2] * src[x + 2] + filter[3] * src[x + 3]) >> 4;
        }
        // Handle odd width if necessary
        if (x < width)
            temp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;

        // Copy from temp to destination consecutively
        for (x = 0; x < width; x++)
            dst[x] = temp[x];

        src += srcstride;
        dst += 64;
    }
}
