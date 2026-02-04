#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_row = row;
    for (row = 16; row--;) {
        temp_row ^= row;
        dst[temp_row % 32] = (uint8_t)(temp_row * 2);
        dst += dst_stride;
        dst[(temp_row + 8) % 32] = dst[0] + 1;
        dst += dst_stride;
    }
    row = temp_row;
}
