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
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        dst[x] = ((((msrc[x] - half) * (int64_t)(((asrc[x] >> 1) & 1) + asrc[x]))) >> shift) + half;
        if (x + 1 < w) {
            dst[x+1] = ((((msrc[x+1] - half) * (int64_t)(((asrc[x+1] >> 1) & 1) + asrc[x+1]))) >> shift) + half;
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
