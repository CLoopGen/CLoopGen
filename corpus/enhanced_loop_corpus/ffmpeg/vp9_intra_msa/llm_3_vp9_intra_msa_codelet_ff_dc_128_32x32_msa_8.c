#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_dst = dst;
    ptrdiff_t stride_x4 = dst_stride * 4;
    for (row = 8; row--;) {
        temp_dst += stride_x4;
        temp_dst += stride_x4;
    }
    dst = temp_dst;
}
