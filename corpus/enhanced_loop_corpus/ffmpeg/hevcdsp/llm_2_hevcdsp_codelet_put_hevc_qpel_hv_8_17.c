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
    // Variant 1: Consecutive memory access with array indexing restructured for temporal locality
    // Here, we precompute effective source addresses to enable more predictable access patterns.
    // We also unroll the inner loop by a factor of 2 to improve spatial locality and reduce loop overhead.
    int y_shifted;
    for (y = 0; y < height + 7; y++) {
        uint8_t *src_row = src;
        for (x = 0; x < width - 1; x += 2) {
            // Access two elements at once to promote vectorization and cache reuse
            int offset_x0 = x;
            int offset_x1 = x + 1;
            tmp[offset_x0] = (
                filter[0] * src_row[offset_x0 - 3] +
                filter[1] * src_row[offset_x0 - 2] +
                filter[2] * src_row[offset_x0 - 1] +
                filter[3] * src_row[offset_x0] +
                filter[4] * src_row[offset_x0 + 1] +
                filter[5] * src_row[offset_x0 + 2] +
                filter[6] * src_row[offset_x0 + 3] +
                filter[7] * src_row[offset_x0 + 4]
            ) >> 0;

            tmp[offset_x1] = (
                filter[0] * src_row[offset_x1 - 3] +
                filter[1] * src_row[offset_x1 - 2] +
                filter[2] * src_row[offset_x1 - 1] +
                filter[3] * src_row[offset_x1] +
                filter[4] * src_row[offset_x1 + 1] +
                filter[5] * src_row[offset_x1 + 2] +
                filter[6] * src_row[offset_x1 + 3] +
                filter[7] * src_row[offset_x1 + 4]
            ) >> 0;
        }
        // Handle remaining element if width is odd
        if (x < width) {
            tmp[x] = (
                filter[0] * src[x - 3] +
                filter[1] * src[x - 2] +
                filter[2] * src[x - 1] +
                filter[3] * src[x] +
                filter[4] * src[x + 1] +
                filter[5] * src[x + 2] +
                filter[6] * src[x + 3] +
                filter[7] * src[x + 4]
            ) >> 0;
        }
        src += srcstride;
        tmp += 64;
    }
}
