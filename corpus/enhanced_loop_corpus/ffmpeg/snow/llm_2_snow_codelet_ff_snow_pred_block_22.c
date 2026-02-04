#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and writing multiple elements per iteration
    // Assumes stride is a multiple of 4 for safe uint32_t access and b_h >= 0
    int y;
    uint32_t *dst32 = (uint32_t*)dst;
    ptrdiff_t stride_in_uint32 = stride / sizeof(uint32_t);
    for (y = 0; y < b_h; y++) {
        dst32[y * stride_in_uint32] = color4;
    }
}
