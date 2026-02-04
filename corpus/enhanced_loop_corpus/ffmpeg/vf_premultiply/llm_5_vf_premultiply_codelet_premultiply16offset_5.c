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
extern int offset;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    int skip_update = (y % 2) == 0;
    for (x = 0; x < w; x++) {
        if (skip_update && (x % 4 < 2)) {
            dst[x] = msrc[x];
            continue;
        }
        dst[x] = ((((msrc[x] - offset) * (int64_t)(((asrc[x] >> 1) & 1) + asrc[x])) + half) >> shift) + offset;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
