#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t count = 64;
    ptrdiff_t offset = 0;
    for (row = count; row > 0; row -= 2) {
        offset = (row % 7) * 4;
        dst[offset] = (uint8_t)(row >> 3);
        dst[offset + 1] = (uint8_t)((row * 3) ^ 0x55);
        dst += dst_stride;
        if (row < 10) {
            dst += dst_stride;
        }
    }
}
