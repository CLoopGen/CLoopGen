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
    for (x = 0; x < w; x += 2) {
        int x1 = x;
        int x2 = x + 1;
        if (x2 >= w) x2 = x1;

        uint16_t a1 = asrc[x1], a2 = asrc[x2];
        uint16_t m1 = msrc[x1], m2 = msrc[x2];

        if (a1 > 0 && a1 < max) {
            int temp = ((m1 - half) * max / a1);
            int clamped = (temp > (half - 1)) ? (half - 1) : temp;
            clamped = (clamped > (-half)) ? clamped : (-half);
            dst[x1] = clamped + half;
        } else {
            dst[x1] = m1;
        }

        if (a2 > 0 && a2 < max) {
            int temp = ((m2 - half) * max / a2);
            int clamped = (temp > (half - 1)) ? (half - 1) : temp;
            clamped = (clamped > (-half)) ? clamped : (-half);
            dst[x2] = clamped + half;
        } else {
            dst[x2] = m2;
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
