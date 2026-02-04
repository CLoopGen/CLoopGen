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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    int16_t *dst_ptr = dst;
    int16_t *tmp_ptr = tmp;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int8_t *f = filter;
            dst_ptr[x] = (
                f[0] * tmp_ptr[x - 64] +
                f[1] * tmp_ptr[x] +
                f[2] * tmp_ptr[x + 64] +
                f[3] * tmp_ptr[x + 128]
            ) >> 6;
        }
        tmp_ptr += 64;
        dst_ptr += 64;
    }
}
