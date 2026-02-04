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
for (y = 0; y < h; y++) {
    if (w > 0) {
        dst[0] = bsrc[0];
        for (x = 1; x < w; x++) {
            int diff = osrc[x] - bsrc[x];
            int product = msrc[x] * diff;
            dst[x] = bsrc[x] + ((product + 128) >> 8);
        }
    }
    dst += dlinesize;
    bsrc += blinesize;
    osrc += olinesize;
    msrc += mlinesize;
}
}
