#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x++) {
        int coeff_shift = (y < height) ? 1 : 2;
        int adjusted_shift = (9 - coeff_shift);
        tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> adjusted_shift;
    }
    src += srcstride;
    tmp += 64;
}
}
