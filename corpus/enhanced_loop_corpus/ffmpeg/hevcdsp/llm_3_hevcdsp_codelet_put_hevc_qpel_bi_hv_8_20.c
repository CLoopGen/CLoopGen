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
    // Variant 2: Strided memory access with reversed inner loop and offset indexing
    ptrdiff_t stride = srcstride;
    for (y = 0; y < height + 7; y++) {
        uint8_t *row_src = &src[y * stride];
        int16_t *row_tmp = &tmp[y * 64];
        for (x = width - 1; x >= 0; x--) {  // Reverse iteration
            row_tmp[x] = (
                filter[0] * row_src[x - 3] +
                filter[1] * row_src[x - 2] +
                filter[2] * row_src[x - 1] +
                filter[3] * row_src[x]     +
                filter[4] * row_src[x + 1] +
                filter[5] * row_src[x + 2] +
                filter[6] * row_src[x + 3] +
                filter[7] * row_src[x + 4]
            ) >> (8 - 8);
        }
    }
}
