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
    // Variant 2: Strided memory access with reversed traversal order (backward)
    for (y = 0; y < h; y++) {
        uint8_t *d = dst;
        const uint8_t *s = src;
        // Access elements in reverse order with stride of 1 but logic adjusted
        for (x = 3; x >= 0; x--) {
            d[x] = (a * s[x] + b * s[x + 1] + 4) >> 3;
        }
        dst += dstride;
        src += sstride;
    }
}
