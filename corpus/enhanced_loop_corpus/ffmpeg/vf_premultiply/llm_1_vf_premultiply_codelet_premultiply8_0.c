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
    x = 0;
    if (x < w) {
        do {
            dst[x] = ((msrc[x] * (((asrc[x] >> 1) & 1) + asrc[x])) + 128) >> 8;
            x++;
        } while (x < w);
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
