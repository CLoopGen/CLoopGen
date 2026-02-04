#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t mlinesize;
extern ptrdiff_t alinesize;
extern ptrdiff_t dlinesize;
extern int w;
extern int h;
extern int half;
extern int max;
extern  uint16_t *msrc;
extern  uint16_t *asrc;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        if (asrc[x] > 0 && asrc[x] < max)
            dst[x] = (((((msrc[x] - half) * max / asrc[x]) > (half - 1) ? (half - 1) : ((msrc[x] - half) * max / asrc[x]))) > (-half) ? ((((msrc[x] - half) * max / asrc[x]) > (half - 1) ? (half - 1) : ((msrc[x] - half) * max / asrc[x]))) : (-half)) + half;
        else
            dst[x] = msrc[x];
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}

}
