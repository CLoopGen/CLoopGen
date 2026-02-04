#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Transposed Indexing
    // Process every 2nd element first, then the rest (simulated strided access pattern)
    // This changes access locality and may improve cache behavior in some contexts
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 2) {
            // Even indices first
            dst[x] = (
                filter[0] * src[x - 3 * srcstride] +
                filter[1] * src[x - 2 * srcstride] +
                filter[2] * src[x - srcstride] +
                filter[3] * src[x] +
                filter[4] * src[x + srcstride] +
                filter[5] * src[x + 2 * srcstride] +
                filter[6] * src[x + 3 * srcstride] +
                filter[7] * src[x + 4 * srcstride]
            ) >> 8;
        }
        for (x = 1; x < width; x += 2) {
            // Odd indices second
            dst[x] = (
                filter[0] * src[x - 3 * srcstride] +
                filter[1] * src[x - 2 * srcstride] +
                filter[2] * src[x - srcstride] +
                filter[3] * src[x] +
                filter[4] * src[x + srcstride] +
                filter[5] * src[x + 2 * srcstride] +
                filter[6] * src[x + 3 * srcstride] +
                filter[7] * src[x + 4 * srcstride]
            ) >> 8;
        }
        src += srcstride;
        dst += 64;
    }
}
