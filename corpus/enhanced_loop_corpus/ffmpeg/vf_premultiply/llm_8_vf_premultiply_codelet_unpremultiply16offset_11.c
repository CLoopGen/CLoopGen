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
        uint16_t val;
        if (asrc[x] > 0 && asrc[x] < max) {
            unsigned int adjusted = (msrc[x] - offset) > 0 ? (msrc[x] - offset) : 0;
            unsigned int scaled = adjusted * (unsigned int)max / asrc[x] + offset;
            val = scaled > max ? max : scaled;
            val = val > 0 ? val : 0;
        } else {
            val = msrc[x];
        }
        dst[x] = val;

        if (x + 1 < w) {
            uint16_t val2;
            if (asrc[x+1] > 0 && asrc[x+1] < max) {
                unsigned int adjusted = (msrc[x+1] - offset) > 0 ? (msrc[x+1] - offset) : 0;
                unsigned int scaled = adjusted * (unsigned int)max / asrc[x+1] + offset;
                val2 = scaled > max ? max : scaled;
                val2 = val2 > 0 ? val2 : 0;
            } else {
                val2 = msrc[x+1];
            }
            dst[x+1] = val2;
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
