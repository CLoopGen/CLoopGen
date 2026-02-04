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
        uint16_t alpha = asrc[x];
        uint16_t src_val = msrc[x];
        uint16_t adjusted = src_val > offset ? src_val - offset : 0;
        uint16_t result;

        if (alpha == 0) {
            result = src_val;
        } else if (alpha >= max) {
            result = src_val;
        } else {
            unsigned int scaled = (unsigned int)adjusted * max / alpha + offset;
            result = scaled > max ? max : (scaled < 0 ? 0 : scaled);
        }

        dst[x] = result;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
