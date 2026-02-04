#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Using Index Scaling
    for (y = 0; y < height; y++) {
        int stride_offset = y * 64;
        for (x = 0; x < width; x++) {
            int idx = x + stride_offset;
            dst[idx] = (
                filter[0] * tmp[idx - 64] +
                filter[1] * tmp[idx] +
                filter[2] * tmp[idx + 64] +
                filter[3] * tmp[idx + 128]
            ) >> 6;
        }
    }
}
