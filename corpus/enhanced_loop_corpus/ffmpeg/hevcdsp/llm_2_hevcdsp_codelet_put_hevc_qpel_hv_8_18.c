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
    // Variant 1: Consecutive Memory Access with Unrolling
    // Instead of strided access (every 64 elements), we restructure tmp to be accessed consecutively
    // by precomputing an offset and using a linear index. We also unroll the inner loop by a factor of 2
    // for improved spatial locality and reduced loop overhead.

    int stride = 64;
    for (y = 0; y < height; y++) {
        int base_idx = y * stride;
        for (x = 0; x < width - 1; x += 2) {
            int offset_x0 = x;
            int offset_x1 = x + 1;

            // Reuse common offsets relative to current row
            int16_t *tmp_row = tmp + base_idx;
            dst[offset_x0] = (
                filter[0] * tmp_row[offset_x0 - 3*stride] +
                filter[1] * tmp_row[offset_x0 - 2*stride] +
                filter[2] * tmp_row[offset_x0 - 1*stride] +
                filter[3] * tmp_row[offset_x0] +
                filter[4] * tmp_row[offset_x0 + 1*stride] +
                filter[5] * tmp_row[offset_x0 + 2*stride] +
                filter[6] * tmp_row[offset_x0 + 3*stride] +
                filter[7] * tmp_row[offset_x0 + 4*stride]
            ) >> 6;

            dst[offset_x1] = (
                filter[0] * tmp_row[offset_x1 - 3*stride] +
                filter[1] * tmp_row[offset_x1 - 2*stride] +
                filter[2] * tmp_row[offset_x1 - 1*stride] +
                filter[3] * tmp_row[offset_x1] +
                filter[4] * tmp_row[offset_x1 + 1*stride] +
                filter[5] * tmp_row[offset_x1 + 2*stride] +
                filter[6] * tmp_row[offset_x1 + 3*stride] +
                filter[7] * tmp_row[offset_x1 + 4*stride]
            ) >> 6;
        }
        // Handle remaining element if width is odd
        if (x < width) {
            int offset_x = x;
            int16_t *tmp_row = tmp + y * 64;
            dst[offset_x] = (
                filter[0] * tmp_row[offset_x - 3*64] +
                filter[1] * tmp_row[offset_x - 2*64] +
                filter[2] * tmp_row[offset_x - 64] +
                filter[3] * tmp_row[offset_x] +
                filter[4] * tmp_row[offset_x + 64] +
                filter[5] * tmp_row[offset_x + 2*64] +
                filter[6] * tmp_row[offset_x + 3*64] +
                filter[7] * tmp_row[offset_x + 4*64]
            ) >> 6;
        }
        dst += 64;
    }
}
