#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y += 2, dst += stride * 2, src += stride * 2) {
        // Unrolled to process two iterations at once, reducing loop overhead
        uint8_t tmp1 = src[0];
        uint8_t tmp2 = src[stride];
        dst[0] = tmp1 + 1;
        dst[stride] = tmp2 + 1;
    }
    // Handle odd-height case if needed
    if (y == height + 1) {
        dst -= stride;
        src -= stride;
        dst[0] = src[0] + 1;
    }
}
