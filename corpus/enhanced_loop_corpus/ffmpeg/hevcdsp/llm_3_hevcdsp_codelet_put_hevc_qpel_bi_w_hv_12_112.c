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
for (y = 0; y < height + 7; y++) {
    const uint16_t* base_src = src + y * srcstride;
    int16_t* base_tmp = tmp + y * 64;
    for (x = 0; x < width; x += 4) {
        for (int k = 0; k < 4 && (x + k) < width; k++) {
            int idx = x + k;
            base_tmp[idx] = (int16_t)((filter[0] * base_src[idx - 3] +
                                       filter[1] * base_src[idx - 2] +
                                       filter[2] * base_src[idx - 1] +
                                       filter[3] * base_src[idx] +
                                       filter[4] * base_src[idx + 1] +
                                       filter[5] * base_src[idx + 2] +
                                       filter[6] * base_src[idx + 3] +
                                       filter[7] * base_src[idx + 4]) >> 4);
        }
    }
}
}
