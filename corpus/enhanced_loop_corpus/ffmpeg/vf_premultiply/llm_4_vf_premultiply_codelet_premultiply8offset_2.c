#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int offset;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int alpha_val = asrc[x];
        int mid = (alpha_val >> 1) & 1;
        int multiplier = mid + alpha_val;
        int temp = (msrc[x] - offset) * multiplier;
        dst[x] = ((temp + 128) >> 8) + offset;
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
