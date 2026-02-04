#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x += 2) {
        int src_idx1 = x - 3;
        int src_idx2 = x - 2;
        int src_idx3 = x - 1;
        int src_idx4 = x;
        int src_idx5 = x + 1;
        int src_idx6 = x + 2;
        int src_idx7 = x + 3;
        int src_idx8 = x + 4;

        tmp[x] = (filter[0] * src[src_idx1] +
                  filter[1] * src[src_idx2] +
                  filter[2] * src[src_idx3] +
                  filter[3] * src[src_idx4] +
                  filter[4] * src[src_idx5] +
                  filter[5] * src[src_idx6] +
                  filter[6] * src[src_idx7] +
                  filter[7] * src[src_idx8]) >> 8;

        if (x + 1 < width) {
            tmp[x + 1] = (filter[0] * src[src_idx1 + 1] +
                          filter[1] * src[src_idx2 + 1] +
                          filter[2] * src[src_idx3 + 1] +
                          filter[3] * src[src_idx4 + 1] +
                          filter[4] * src[src_idx5 + 1] +
                          filter[5] * src[src_idx6 + 1] +
                          filter[6] * src[src_idx7 + 1] +
                          filter[7] * src[src_idx8 + 1]) >> 8;
        }
    }
    src += srcstride;
    tmp += 64;
}
}
