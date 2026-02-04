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
    uint8_t prev_dst = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int diff = osrc[x] - bsrc[x];
            int product = msrc[x] * diff;
            dst[x] = prev_dst + bsrc[x] + ((product + 128) >> 8);
            prev_dst = dst[x] & 0xFF;
        }
        dst += dlinesize;
        bsrc += blinesize;
        osrc += olinesize;
        msrc += mlinesize;
        prev_dst = 0;
    }
}
