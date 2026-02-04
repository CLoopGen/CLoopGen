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
extern int offset;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int masked_alpha = (asrc[x] >> 1) & 1;
        int effective_alpha = masked_alpha + asrc[x];
        if (effective_alpha > 32) {
            dst[x] = ((((msrc[x] - offset) * effective_alpha) + 128) >> 8) + offset;
        } else {
            dst[x] = msrc[x];
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
