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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    int16_t *dst_ptr = dst;
    uint16_t *src_row = src;
    for (y = 0; y < height; y++) {
        uint16_t *src_ptr = src_row;
        for (x = 0; x + 1 < width; x += 2) {
            dst_ptr[x]     = ((int16_t)(src_ptr[x]     << (14 - 12)));
            dst_ptr[x + 1] = ((int16_t)(src_ptr[x + 1] << (14 - 12)));
        }
        if (x < width) {
            dst_ptr[x] = ((int16_t)(src_ptr[x] << (14 - 12)));
        }
        src_row += srcstride;
        dst_ptr += 64;
    }
}
