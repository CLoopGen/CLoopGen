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



void loop() {
    ptrdiff_t dy = dlinesize / 2;
    ptrdiff_t my = mlinesize / 2;
    ptrdiff_t ay = alinesize / 2;
    uint16_t temp_val;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (asrc[x] > 0 && asrc[x] < max) {
                int diff = msrc[x] - half;
                int scaled = diff * max / asrc[x];
                temp_val = (scaled > (half - 1)) ? (half - 1) : scaled;
                temp_val = (temp_val > -half) ? temp_val : -half;
                dst[x] = temp_val + half;
            } else {
                dst[x] = msrc[x];
            }
        }
        dst += dy;
        msrc += my;
        asrc += ay;
    }
}
