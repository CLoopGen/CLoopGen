#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int half;
extern int shift;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t moffset = 0, aoffset = 0, doffset = 0;
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int idx = x;
        dst[doffset + idx] = ((((msrc[moffset + idx] - half) * (int64_t)(((asrc[aoffset + idx] >> 1) & 1) + asrc[aoffset + idx]))) >> shift) + half;
    }
    doffset += dlinesize / 2;
    moffset += mlinesize / 2;
    aoffset += alinesize / 2;
}
}
