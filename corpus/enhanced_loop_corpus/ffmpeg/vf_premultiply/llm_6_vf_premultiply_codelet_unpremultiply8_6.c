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
    uint8_t temp_val;
    for (x = 0; x < w; x++) {
        temp_val = asrc[x];
        if (temp_val > 0 && temp_val < 255) {
            int scaled = msrc[x] * 255 / temp_val;
            dst[x] = (scaled > 255) ? 255 : scaled;
        } else {
            dst[x] = msrc[x];
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
