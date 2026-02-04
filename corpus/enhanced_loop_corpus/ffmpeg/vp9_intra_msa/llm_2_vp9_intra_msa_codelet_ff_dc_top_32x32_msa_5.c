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
    ptrdiff_t double_stride = 2 * dst_stride;
    for (row = 16; row--;) {
        temp_dst += double_stride;
    }
    dst = temp_dst;
}
