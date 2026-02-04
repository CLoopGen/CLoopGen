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
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic (unrolled and restructured for linear src traversal)
    int16_t *dst_ptr = dst;
    uint16_t *src_base = src;
    for (y = 0; y < height; y++) {
        uint16_t *src_row = src_base + y * srcstride;
        for (x = 0; x < width; x++) {
            const uint16_t *s = src_row + x;
            dst_ptr[x] = (
                filter[0] * s[-3*srcstride] +
                filter[1] * s[-2*srcstride] +
                filter[2] * s[-1*srcstride] +
                filter[3] * s[0] +
                filter[4] * s[1*srcstride] +
                filter[5] * s[2*srcstride] +
                filter[6] * s[3*srcstride] +
                filter[7] * s[4*srcstride]
            ) >> 4;
        }
        dst_ptr += 64;
    }
}
