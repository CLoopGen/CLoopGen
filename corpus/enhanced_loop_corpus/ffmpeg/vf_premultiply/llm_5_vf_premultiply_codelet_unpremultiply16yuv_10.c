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
        int alpha_nonzero = asrc[x] != 0;
        int alpha_in_range = asrc[x] < max;
        int use_clamped = alpha_nonzero && alpha_in_range;
        int temp = use_clamped ? (((msrc[x] - half) * max / asrc[x]) > (half - 1) ? (half - 1) : ((msrc[x] - half) * max / asrc[x])) : (msrc[x] - half);
        int clamped_val = (temp < -half) ? -half : temp;
        dst[x] = clamped_val + half;
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
