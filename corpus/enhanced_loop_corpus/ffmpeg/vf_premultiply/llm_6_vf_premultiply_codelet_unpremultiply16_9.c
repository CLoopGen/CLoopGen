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
    uint16_t temp;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            temp = asrc[x];
            if (temp > 0 && temp < max) {
                uint32_t product = (uint32_t)msrc[x] * max;
                uint32_t quotient = product / temp;
                dst[x] = (quotient > max) ? max : (uint16_t)quotient;
            } else {
                dst[x] = msrc[x];
            }
        }
        dst += dlinesize / 2;
        msrc += mlinesize / 2;
        asrc += alinesize / 2;
    }
}
