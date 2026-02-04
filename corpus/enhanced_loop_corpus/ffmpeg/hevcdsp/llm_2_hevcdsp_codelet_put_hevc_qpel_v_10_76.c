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
    // Variant 1: Consecutive memory access by precomputing source row pointers
    int16_t *dst_ptr = dst;
    uint16_t *src_base = src;
    for (y = 0; y < height; y++) {
        uint16_t *src_row = src_base + y * srcstride;
        const int offset[8] = { -3*srcstride, -2*srcstride, -1*srcstride, 0, srcstride, 2*srcstride, 3*srcstride, 4*srcstride };
        for (x = 0; x < width; x++) {
            int sum = 0;
            for (int k = 0; k < 8; k++) {
                sum += filter[k] * src_row[x + offset[k]];
            }
            dst_ptr[x] = sum >> 2;
        }
        dst_ptr += 64;
    }
}
