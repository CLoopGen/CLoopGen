#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        uint8_t *src_row = src + y * srcstride;
        int16_t *dst_row = dst + y * 64;
        for (x = 0; x < width; x += 4) {
            dst_row[x]     = (filter[0] * src_row[x - srcstride] + filter[1] * src_row[x] + 
                              filter[2] * src_row[x + srcstride] + filter[3] * src_row[x + 2 * srcstride]) >> 8;
            dst_row[x + 1] = (filter[0] * src_row[x + 1 - srcstride] + filter[1] * src_row[x + 1] + 
                              filter[2] * src_row[x + 1 + srcstride] + filter[3] * src_row[x + 1 + 2 * srcstride]) >> 8;
            dst_row[x + 2] = (filter[0] * src_row[x + 2 - srcstride] + filter[1] * src_row[x + 2] + 
                              filter[2] * src_row[x + 2 + srcstride] + filter[3] * src_row[x + 2 + 2 * srcstride]) >> 8;
            dst_row[x + 3] = (filter[0] * src_row[x + 3 - srcstride] + filter[1] * src_row[x + 3] + 
                              filter[2] * src_row[x + 3 + srcstride] + filter[3] * src_row[x + 3 + 2 * srcstride]) >> 8;
        }
    }
}
