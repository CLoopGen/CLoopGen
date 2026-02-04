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
        uint8_t alpha = asrc[x];
        uint8_t mval = msrc[x];
        uint8_t clamped_m = (mval > offset) ? (mval - offset) : 0;
        if (alpha == 0) {
            dst[x] = mval;
            continue;
        }
        if (alpha == 255) {
            dst[x] = (clamped_m + offset > 255) ? 255 : clamped_m + offset;
        } else {
            int temp = clamped_m * 255 / alpha + offset;
            dst[x] = (temp > 255) ? 255 : temp;
        }
    }
    dst += dlinesize;
    msrc += mlinesize;
    asrc += alinesize;
}
}
