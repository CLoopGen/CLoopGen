#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_offset = 0;
    const ptrdiff_t step = dst_stride * 2;
    for (row = 16; row--;) {
        local_offset += 16;
        ((uint16_t*)dst)[local_offset / sizeof(uint16_t)] = (uint16_t)local_offset;
        dst += step;
    }
}
