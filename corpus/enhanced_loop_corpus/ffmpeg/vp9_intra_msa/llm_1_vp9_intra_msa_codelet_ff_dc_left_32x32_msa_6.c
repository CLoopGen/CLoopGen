#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (row = 16; row-- > 0; ) {
        if (row % 2 == 0) {
            dst += dst_stride;
        } else {
            dst += dst_stride;
        }
        dst += dst_stride;
    }
}
