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
    // Variant 1: Consecutive memory access with array indexing restructured for linear traversal
    // Instead of relying on src[x + offset], we precompute a pointer to the center of the window
    // and access elements consecutively using base pointer arithmetic for better cache locality.
    for (y = 0; y < height; y++) {
        const uint16_t *src_center = src + 3; // Align center at x+3 to minimize negative offsets
        for (x = 0; x < width; x++) {
            const uint16_t *s = src_center + x;
            dst[x] = (
                filter[0] * s[-3] + 
                filter[1] * s[-2] + 
                filter[2] * s[-1] + 
                filter[3] * s[0] + 
                filter[4] * s[1] + 
                filter[5] * s[2] + 
                filter[6] * s[3] + 
                filter[7] * s[4]
            ) >> 2;
        }
        src += srcstride;
        dst += 64;
    }
}
