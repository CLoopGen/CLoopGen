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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 4) {
        dst[x] = ((((msrc[x] - 128) * (((asrc[x] >> 1) & 1) + asrc[x]) +
                  (msrc[x+1] - 128) * (((asrc[x+1] >> 1) & 1) + asrc[x+1]) +
                  (msrc[x+2] - 128) * (((asrc[x+2] >> 1) & 1) + asrc[x+2]) +
                  (msrc[x+3] - 128) * (((asrc[x+3] >> 1) & 1) + asrc[x+3]))) >> 10) + 128;
    }
    dst += dlinesize * 2;
    msrc += mlinesize * 2;
    asrc += alinesize * 2;
}
}
