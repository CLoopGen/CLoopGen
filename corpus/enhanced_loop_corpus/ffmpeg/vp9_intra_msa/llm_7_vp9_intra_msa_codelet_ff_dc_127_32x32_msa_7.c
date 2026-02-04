#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    ptrdiff_t local_stride = dst_stride;
    for (row = 16; row--;) {
        local_dst += local_stride;
        local_dst += local_stride;
    }
    dst = local_dst;
}
