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
    // Variant 2: Strided memory access with transposed read pattern
    // Access source in a non-consecutive, vertical-first manner (strided across rows)
    // Simulates processing along columns instead of rows, changing spatial locality

    for (x = 0; x < width; x++) {
        const uint16_t *col_src = src + x - 1;  // Base pointer for this column
        for (y = 0; y < height; y++) {
            // Access data vertically: same column, different rows
            dst[y * 64 + x] = (
                filter[0] * col_src[0] +
                filter[1] * col_src[1] +
                filter[2] * col_src[2] +
                filter[3] * col_src[3]
            ) >> 4;
            col_src += srcstride;  // Move down one row
        }
    }

    // Adjust final pointers as in original (dst ends at correct position)
    src += height * srcstride;
    dst += height * 64;
}
