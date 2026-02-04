#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int16_t prev_tmp_val = 0;
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x++) {
        int16_t dot_product = (filter[0] * src[x - 3] +
                               filter[1] * src[x - 2] +
                               filter[2] * src[x - 1] +
                               filter[3] * src[x]     +
                               filter[4] * src[x + 1] +
                               filter[5] * src[x + 2] +
                               filter[6] * src[x + 3] +
                               filter[7] * src[x + 4]) >> 2;
        tmp[x] = dot_product + prev_tmp_val;
        prev_tmp_val = dot_product;
    }
    src += srcstride;
    tmp += 64;
    prev_tmp_val = 0;
}
}
