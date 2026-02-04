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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        if (asrc[x] > 0 && asrc[x] < max)
            dst[x] = ((((msrc[x] - half) * max / asrc[x]) > (half - 1) ? (half - 1) : ((msrc[x] - half) * max / asrc[x]))) + half;
        else
            dst[x] = msrc[x];
    }
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
    dst += dlinesize / 2;

    if (y + 1 < h) {
        for (x = 0; x < w; x++) {
            int temp = (msrc[x] - half) * max;
            int ratio = (asrc[x] > 0 && asrc[x] < max) ? temp / asrc[x] : (msrc[x] - half);
            int clamped = ratio;
            if (clamped > half - 1) clamped = half - 1;
            if (clamped < -half) clamped = -half;
            dst[x] = clamped + half;
        }
        msrc += mlinesize / 2;
        asrc += alinesize / 2;
        dst += dlinesize / 2;
    }
}
}
