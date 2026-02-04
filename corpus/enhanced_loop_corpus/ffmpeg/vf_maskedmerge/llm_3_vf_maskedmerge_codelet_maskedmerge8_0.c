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
ptrdiff_t idx = 0;
ptrdiff_t bidx = 0, oidx = 0, midx = 0;
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        idx = y * (dlinesize) + x;
        bidx = y * (blinesize) + x;
        oidx = y * (olinesize) + x;
        midx = y * (mlinesize) + x;
        dst[idx] = bsrc[bidx] + ((msrc[midx] * (osrc[oidx] - bsrc[bidx]) + 128) >> 8);
    }
}
}
