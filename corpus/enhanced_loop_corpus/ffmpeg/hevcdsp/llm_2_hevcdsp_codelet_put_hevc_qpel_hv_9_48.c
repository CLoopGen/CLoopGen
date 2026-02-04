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
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // Instead of using array indexing with large strides, rebase tmp to allow sequential access
    // We precompute offsets as consecutive elements by adjusting the base pointer
    int16_t *tmp_base = tmp - 3 * 64;  // Align base so that [x] corresponds to tmp[x - 3*64]
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            dst[x] = (
                filter[0] * tmp_base[x + 0 * 64] +
                filter[1] * tmp_base[x + 1 * 64] +
                filter[2] * tmp_base[x + 2 * 64] +
                filter[3] * tmp_base[x + 3 * 64] +
                filter[4] * tmp_base[x + 4 * 64] +
                filter[5] * tmp_base[x + 5 * 64] +
                filter[6] * tmp_base[x + 6 * 64] +
                filter[7] * tmp_base[x + 7 * 64]
            ) >> 6;
        }
        tmp += 64;
        dst += 64;
        tmp_base += 64;  // Maintain alignment for next row
    }
}
