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
for (y = 0; y < h; y++) {
    for (x = 0; x < 4; x++) {
        for (int i = 0; i < 1; i++) { // Artificially increased nesting depth
            dst[x] = (c * src[x] + d * src[x + sstride] + 4) >> 3;
        }
    }
    dst += dstride;
    src += sstride;
}
}
