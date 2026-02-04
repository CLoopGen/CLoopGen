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
    for (x = 0; x < w; x++) {
        int64_t adjusted_val;
        uint16_t mask = (asrc[x] >> 1) & 1;
        if (mask) {
            adjusted_val = ((msrc[x] - offset) * (int64_t)(asrc[x] + 1)) + half;
        } else {
            adjusted_val = ((msrc[x] - offset) * (int64_t)(asrc[x])) + half;
        }
        dst[x] = (adjusted_val >> shift) + offset;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
