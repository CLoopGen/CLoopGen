#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    for (i = 0; i < height; i++) {
        uint8_t *dst_row = dst;
        uint8_t *src_row = src;
        j = 0;
        // Process two elements at a time for better spatial locality
        for (; j <= width - 2; j += 2) {
            dst_row[j]     = src_row[j];
            dst_row[j + 1] = src_row[j + 1];
        }
        // Handle remaining element if width is odd
        if (j < width) {
            dst_row[j] = src_row[j];
        }
        dst += stride_dst;
        src += stride_src;
    }
}
