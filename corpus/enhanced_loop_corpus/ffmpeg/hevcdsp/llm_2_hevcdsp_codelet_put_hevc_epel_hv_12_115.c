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
    // Variant 1: Consecutive memory access with array indexing restructured for spatial locality
    for (y = 0; y < height + 3; y++) {
        uint16_t *src_row = &src[y * srcstride];
        int16_t *tmp_row = &tmp[y * 64];
        for (x = 0; x < width; x++) {
            tmp_row[x] = (int16_t)((filter[0] * src_row[x - 1] +
                                   filter[1] * src_row[x] +
                                   filter[2] * src_row[x + 1] +
                                   filter[3] * src_row[x + 2]) >> 4);
        }
    }
}
