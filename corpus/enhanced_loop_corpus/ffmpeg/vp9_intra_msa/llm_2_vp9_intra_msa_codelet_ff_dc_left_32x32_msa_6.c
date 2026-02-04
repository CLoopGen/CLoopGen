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
    for (row = 16; row--;) {
        temp_dst += dst_stride * 2;
    }
    dst = temp_dst;
}
