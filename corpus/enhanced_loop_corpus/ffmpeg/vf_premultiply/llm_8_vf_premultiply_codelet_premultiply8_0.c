#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *msrc;
extern  uint8_t *asrc;
extern uint8_t *dst;
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        uint16_t mval1 = msrc[x];
        uint16_t aval1 = asrc[x];
        uint16_t mval2 = (x+1 < w) ? msrc[x+1] : msrc[x];
        uint16_t aval2 = (x+1 < w) ? asrc[x+1] : asrc[x];
        dst[x] = ((mval1 * (((aval1 >> 1) & 1) + aval1)) + 128) >> 8;
        if (x+1 < w) {
            dst[x+1] = ((mval2 * (((aval2 >> 1) & 1) + aval2)) + 128) >> 8;
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
