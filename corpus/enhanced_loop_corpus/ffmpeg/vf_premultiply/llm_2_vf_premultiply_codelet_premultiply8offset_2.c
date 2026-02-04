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
    for (x = 0; x < w; x += 2) {
        dst[x] = ((((msrc[x] - offset) * (((asrc[x] >> 1) & 1) + asrc[x])) + 128) >> 8) + offset;
        if (x + 1 < w) {
            dst[x + 1] = ((((msrc[x + 1] - offset) * (((asrc[x + 1] >> 1) & 1) + asrc[x + 1])) + 128) >> 8) + offset;
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
