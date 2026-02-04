#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (uint32_t outer = 8; outer--; ) {
        for (row = 2; row--; ) {
            dst += dst_stride;
        }
    }
}
