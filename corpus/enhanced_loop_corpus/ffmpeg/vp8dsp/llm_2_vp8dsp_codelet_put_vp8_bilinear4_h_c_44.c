#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    for (y = 0; y < h; y++) {
        uint8_t *d = dst;
        const uint8_t *s = src;
        // Unroll by 2 to enable consecutive access pattern in pairs
        for (x = 0; x < 4; x += 2) {
            d[x]     = (a * s[x]     + b * s[x + 1]     + 4) >> 3;
            d[x + 1] = (a * s[x + 1] + b * s[x + 2]     + 4) >> 3;
        }
        dst += dstride;
        src += sstride;
    }
}
