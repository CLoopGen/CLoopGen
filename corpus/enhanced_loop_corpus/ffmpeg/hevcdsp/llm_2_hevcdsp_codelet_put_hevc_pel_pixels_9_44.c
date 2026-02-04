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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes width is even and accesses two elements at a time for more sequential access pattern
    for (y = 0; y < height; y++) {
        int x = 0;
        for (; x < width - 1; x += 2) {
            dst[x]     = src[x]     << (14 - 9);
            dst[x + 1] = src[x + 1] << (14 - 9);
        }
        // Handle remaining element if width is odd
        if (x < width) {
            dst[x] = src[x] << (14 - 9);
        }
        src += srcstride;
        dst += 64;
    }
}
