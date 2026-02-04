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
    for (x = 0; x < w; x++) {
        uint16_t mval = msrc[x] - offset;
        uint16_t aval = asrc[x];
        if (aval <= 0 || aval >= max) {
            dst[x] = msrc[x];
            continue;
        }
        uint32_t temp = ((mval > 0 ? mval : 0) * (unsigned int)max / aval) + offset;
        dst[x] = (temp > max ? max : temp) > 0 ? (temp > max ? max : temp) : 0;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
