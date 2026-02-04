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
    // Variant 2: Strided memory access using a fixed stride pattern across source buffer, simulating non-contiguous sampling
    const int sample_stride = 2; // Access every second pixel — modified access pattern
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int center = x * sample_stride;
            dst[x] = (int16_t)(
                filter[0] * src[center - 6] +  // -3 * 2
                filter[1] * src[center - 4] +  // -2 * 2
                filter[2] * src[center - 2] +  // -1 * 2
                filter[3] * src[center]     +
                filter[4] * src[center + 2] +
                filter[5] * src[center + 4] +
                filter[6] * src[center + 6] +
                filter[7] * src[center + 8]   // +4 * 2
            ) >> (8 - 8);
        }
        src += srcstride;
        dst += 64;
    }
}
