#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // Instead of using array indexing with strided offsets, we precompute pointers to each row used in the filter
    // and access them consecutively, improving spatial locality and enabling better vectorization.

    int16_t *dst_ptr = dst;
    uint16_t *src_base = src;

    for (y = 0; y < height; y++) {
        uint16_t *src_rows[8];
        src_rows[0] = src_base - 3 * srcstride;
        src_rows[1] = src_base - 2 * srcstride;
        src_rows[2] = src_base - srcstride;
        src_rows[3] = src_base;
        src_rows[4] = src_base + srcstride;
        src_rows[5] = src_base + 2 * srcstride;
        src_rows[6] = src_base + 3 * srcstride;
        src_rows[7] = src_base + 4 * srcstride;

        for (x = 0; x < width; x++) {
            int32_t sum = 0;
            for (int k = 0; k < 8; k++) {
                sum += filter[k] * src_rows[k][x];
            }
            dst_ptr[x] = sum >> 1;
        }

        src_base += srcstride;
        dst_ptr += 64;
    }
}
