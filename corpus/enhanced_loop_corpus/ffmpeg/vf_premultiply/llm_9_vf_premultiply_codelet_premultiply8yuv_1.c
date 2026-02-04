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
        int mask = (asrc[x] >> 1) & 1;
        int adjusted_alpha = asrc[x] + mask;
        int diff = msrc[x] - 128;
        int product = diff * adjusted_alpha;
        dst[x] = ((product >> 7) + 128);
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
