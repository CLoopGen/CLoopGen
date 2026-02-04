#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_row;
    uint8_t *local_dst = dst;
    ptrdiff_t local_stride = dst_stride;
    for (local_row = 16; local_row--;) {
        *(volatile uint8_t*)(local_dst) = 0; // Introduce WAW and WAR via memory side effect
        local_dst += local_stride;
        *(volatile uint8_t*)(local_dst) = 0;
        local_dst += local_stride;
    }
    dst = local_dst; // Update original dst only at end to break loop-carried dependency on dst
}
