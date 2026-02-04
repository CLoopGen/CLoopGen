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
    uint16_t temp_val;
    for (x = 0; x < w; x++) {
        temp_val = msrc[x];
        if (asrc[x] > 0 && asrc[x] < max) {
            int adjusted_m = (msrc[x] - offset) > 0 ? (msrc[x] - offset) : 0;
            int scaled = adjusted_m * (unsigned int)max / asrc[x] + offset;
            int clamped = scaled > max ? max : scaled;
            dst[x] = clamped > 0 ? clamped : 0;
        } else {
            dst[x] = temp_val;
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
