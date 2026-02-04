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
    // Variant 2: Strided memory access with reversed traversal order (reverse column iteration)
    // This changes the access pattern to stride backwards through the arrays
    for (y = 0; y < height; y++) {
        for (x = width - 1; x >= 0; x--) {
            dst[x] = src[x] << (14 - 9);
        }
        src += srcstride;
        dst += 64;
    }
}
