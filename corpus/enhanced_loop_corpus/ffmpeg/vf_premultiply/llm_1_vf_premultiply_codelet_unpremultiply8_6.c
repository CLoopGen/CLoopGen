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
    for (x = 0; x < w; x += 2) {
        // Process two elements per iteration if within bounds
        if (asrc[x] > 0 && asrc[x] < 255)
            dst[x] = ((msrc[x] * 255 / asrc[x]) > 255 ? 255 : (msrc[x] * 255 / asrc[x]));
        else
            dst[x] = msrc[x];

        if (x + 1 < w) {
            if (asrc[x+1] > 0 && asrc[x+1] < 255)
                dst[x+1] = ((msrc[x+1] * 255 / asrc[x+1]) > 255 ? 255 : (msrc[x+1] * 255 / asrc[x+1]));
            else
                dst[x+1] = msrc[x+1];
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
