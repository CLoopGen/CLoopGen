#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of strided access in original, we precompute a pointer to current row and access src consecutively
    for (y = 0; y < height; y++) {
        const uint8_t *src_row = src + y * srcstride;
        int16_t *dst_row = dst + y * 64;
        for (x = 0; x < width; x++) {
            int sum = 0;
            sum += filter[0] * src_row[x - 3];
            sum += filter[1] * src_row[x - 2];
            sum += filter[2] * src_row[x - 1];
            sum += filter[3] * src_row[x];
            sum += filter[4] * src_row[x + 1];
            sum += filter[5] * src_row[x + 2];
            sum += filter[6] * src_row[x + 3];
            sum += filter[7] * src_row[x + 4];
            dst_row[x] = sum >> 8;  // equivalent to >> (8 - 8)
        }
    }
}
