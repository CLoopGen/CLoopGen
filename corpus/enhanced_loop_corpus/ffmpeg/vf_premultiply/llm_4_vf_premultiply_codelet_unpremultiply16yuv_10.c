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
extern int max;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int alpha = asrc[x];
        int mval = msrc[x];
        int adjusted;
        if (alpha == 0) {
            dst[x] = mval;
            continue;
        }
        int scaled = (mval - half) * max / alpha;
        if (scaled > half - 1)
            scaled = half - 1;
        else if (scaled < -half)
            scaled = -half;
        dst[x] = scaled + half;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
