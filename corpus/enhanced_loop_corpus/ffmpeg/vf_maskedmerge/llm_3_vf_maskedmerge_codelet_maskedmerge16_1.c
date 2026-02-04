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
ptrdiff_t bstride = blinesize / 2;
ptrdiff_t ostride = olinesize / 2;
ptrdiff_t mstride = mlinesize / 2;
ptrdiff_t dstride = dlinesize / 2;

for (y = 0; y < h; y++) {
    ptrdiff_t bidx = y * bstride;
    ptrdiff_t oidex = y * ostride;
    ptrdiff_t midx = y * mstride;
    ptrdiff_t didx = y * dstride;
    for (x = 0; x < w; x++) {
        dst[didx + x] = bsrc[bidx + x] + ((msrc[midx + x] * (osrc[oidex + x] - bsrc[bidx + x]) + half) >> shift);
    }
}
}
