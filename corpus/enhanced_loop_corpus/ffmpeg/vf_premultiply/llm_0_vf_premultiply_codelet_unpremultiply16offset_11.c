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
extern int offset;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        if (asrc[x] > 0 && asrc[x] < max) {
            uint16_t val = (msrc[x] - offset) > 0 ? (msrc[x] - offset) : 0;
            dst[x] = (val * (unsigned int)max / asrc[x] + offset) > max ? max : (val * (unsigned int)max / asrc[x] + offset);
            dst[x] = dst[x] > 0 ? dst[x] : 0;
        } else {
            dst[x] = msrc[x];
        }
        if (x + 1 < w) {
            if (asrc[x+1] > 0 && asrc[x+1] < max) {
                uint16_t val = (msrc[x+1] - offset) > 0 ? (msrc[x+1] - offset) : 0;
                dst[x+1] = (val * (unsigned int)max / asrc[x+1] + offset) > max ? max : (val * (unsigned int)max / asrc[x+1] + offset);
                dst[x+1] = dst[x+1] > 0 ? dst[x+1] : 0;
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
