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
        uint8_t mval = msrc[x];
        int adjusted;

        adjusted = (alpha > 0) ? ((mval - 128) * 255 / alpha + 128) : mval;
        dst[x] = (alpha > 0 && alpha < 255) ? (adjusted > 255 ? 255 : adjusted) : mval;
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
