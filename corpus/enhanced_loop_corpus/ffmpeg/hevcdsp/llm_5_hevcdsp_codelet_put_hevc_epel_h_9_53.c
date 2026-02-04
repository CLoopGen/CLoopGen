#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        int coeff_shift = (x & 1) ? 1 : -1;
        int idx0 = x - 1, idx1 = x, idx2 = x + 1, idx3 = x + 2;
        int16_t temp = (filter[0 + coeff_shift] * src[idx0] +
                        filter[1 + coeff_shift] * src[idx1] +
                        filter[2 - coeff_shift] * src[idx2] +
                        filter[3 - coeff_shift] * src[idx3]) >> 1;
        dst[x] = temp;
    }
    src += srcstride;
    dst += 64;
}
}
