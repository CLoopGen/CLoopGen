#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bsrc;
extern  uint8_t *osrc;
extern  uint8_t *msrc;
extern uint8_t *dst;
extern ptrdiff_t blinesize;
extern ptrdiff_t olinesize;
extern ptrdiff_t mlinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        uint8_t diff1 = osrc[x] - bsrc[x];
        uint8_t scaled1 = (msrc[x] * diff1 + 128) >> 8;
        dst[x] = bsrc[x] + scaled1;
        if (y + 1 < h) {
            uint8_t diff2 = osrc[x] - bsrc[x];
            uint8_t scaled2 = (msrc[x] * diff2 + 128) >> 8;
            (dst + dlinesize)[x] = bsrc[x] + scaled2;
        }
    }
    dst += 2 * dlinesize;
    bsrc += 2 * blinesize;
    osrc += 2 * olinesize;
    msrc += 2 * mlinesize;
}
}
