#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed inner loop order and offset adjustment
    for (y = 0; y < h; y++) {
        for (x = 3; x >= 0; x--) {
            ptrdiff_t idx = x;
            dst[idx] = (c * src[idx] + d * *(src + sstride + idx) + 4) >> 3;
        }
        dst += dstride;
        src += sstride;
    }
}
