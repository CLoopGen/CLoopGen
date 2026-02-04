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
    uint16_t prev_mval = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int64_t adjusted_m = (x == 0) ? (msrc[x] - half) : (msrc[x] - prev_mval);
            dst[x] = ((adjusted_m * (int64_t)(((asrc[x] >> 1) & 1) + asrc[x]))) >> shift;
            prev_mval = msrc[x];
        }
        dst += dlinesize / 2;
        msrc += mlinesize / 2;
        asrc += alinesize / 2;
    }
}
