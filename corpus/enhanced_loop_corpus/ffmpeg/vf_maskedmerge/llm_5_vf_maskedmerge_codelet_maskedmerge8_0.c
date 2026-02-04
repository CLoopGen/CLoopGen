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
    x = 0;
    for (; x < w; x++) {
        if (!(msrc[x] & 0xFF)) {
            dst[x] = bsrc[x];
        } else {
            int adjusted = osrc[x] - bsrc[x];
            int blended = (msrc[x] * adjusted + 128) >> 8;
            dst[x] = bsrc[x] + blended;
        }
    }
    dst += dlinesize;
    bsrc += blinesize;
    osrc += olinesize;
    msrc += mlinesize;
}
}
