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
    for (x = 0; x < w; x++) {
        uint8_t alpha = asrc[x];
        if (alpha >= 255)
            dst[x] = msrc[x];
        else if (alpha > 0) {
            int temp = (msrc[x] - 128) * 255 / alpha + 128;
            dst[x] = temp > 255 ? 255 : temp;
        }
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
