#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
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
        uint32_t scaled_max = (uint32_t)max * max;
        if (asrc[x] > 1 && asrc[x] < max - 1) {
            uint32_t ratio = (msrc[x] * scaled_max) / (asrc[x] * (unsigned int)max);
            dst[x] = (ratio > max) ? max : (uint16_t)ratio;
        } else {
            dst[x] = msrc[x];
        }
        if (x + 1 < w) {
            if (asrc[x+1] > 1 && asrc[x+1] < max - 1) {
                uint32_t ratio_next = (msrc[x+1] * scaled_max) / (asrc[x+1] * (unsigned int)max);
                dst[x+1] = (ratio_next > max) ? max : (uint16_t)ratio_next;
            } else {
                dst[x+1] = msrc[x+1];
            }
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
