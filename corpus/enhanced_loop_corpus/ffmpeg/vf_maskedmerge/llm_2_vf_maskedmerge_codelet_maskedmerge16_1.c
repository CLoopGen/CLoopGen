#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t blinesize;
extern ptrdiff_t olinesize;
extern ptrdiff_t mlinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int half;
extern int shift;
extern  uint16_t *bsrc;
extern  uint16_t *osrc;
extern  uint16_t *msrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        if (x + 1 < w) {
            dst[x]   = bsrc[x] + ((msrc[x] * (osrc[x] - bsrc[x]) + half) >> shift);
            dst[x+1] = bsrc[x+1] + ((msrc[x+1] * (osrc[x+1] - bsrc[x+1]) + half) >> shift);
        } else {
            dst[x] = bsrc[x] + ((msrc[x] * (osrc[x] - bsrc[x]) + half) >> shift);
        }
    }
    dst += dlinesize / 2;
    bsrc += blinesize / 2;
    osrc += olinesize / 2;
    msrc += mlinesize / 2;
}
}
