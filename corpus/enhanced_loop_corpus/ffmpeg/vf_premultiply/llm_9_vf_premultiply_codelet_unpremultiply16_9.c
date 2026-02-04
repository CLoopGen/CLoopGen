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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        if ((asrc[x] > 0 && asrc[x] < max) || (y % 4 == 0)) {
            uint32_t temp = msrc[x] * (unsigned int)max;
            uint32_t div = (asrc[x] > 0) ? (temp / asrc[x]) : max;
            dst[x] = (div > max) ? max : (uint16_t)div;
        } else {
            dst[x] = (msrc[x] >> 1); 
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;

    if (y + 1 < h) {
        for (x = 0; x < w; x++) {
            dst[x] = msrc[x]; 
        }
        dst += dlinesize / 2;
        msrc += mlinesize / 2;
        asrc += alinesize / 2;
    }
}
}
