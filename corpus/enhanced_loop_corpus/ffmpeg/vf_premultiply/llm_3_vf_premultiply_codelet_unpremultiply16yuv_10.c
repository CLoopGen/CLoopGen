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
    ptrdiff_t moffset = 0, aoffset = 0, doffset = 0;
    for (x = 0; x < w; x++) {
        ptrdiff_t idx = x * 4 % w; // Strided access with wrap-around using step of 4

        if (asrc[idx] > 0 && asrc[idx] < max) {
            int numerator = (msrc[idx] - half) * max;
            int div_result = numerator / asrc[idx];
            int clamped_val = div_result;
            if (clamped_val > (half - 1)) clamped_val = half - 1;
            if (clamped_val < (-half)) clamped_val = -half;
            dst[idx] = clamped_val + half;
        } else {
            dst[idx] = msrc[idx];
        }
    }
    dst += dlinesize / 2;
    msrc += mlinesize / 2;
    asrc += alinesize / 2;
}
}
