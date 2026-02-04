#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    uint16_t *dst_ptr = dst;
    uint16_t *src_ptr = src;
    for (i = 0; i < h; i++) {
        int offset = 0;
        dst_ptr[offset]     = (((A * src_ptr[offset]) + 32) >> 6);
        dst_ptr[offset + 1] = (((A * src_ptr[offset + 1]) + 32) >> 6);
        dst_ptr += stride;
        src_ptr += stride;
    }
}
