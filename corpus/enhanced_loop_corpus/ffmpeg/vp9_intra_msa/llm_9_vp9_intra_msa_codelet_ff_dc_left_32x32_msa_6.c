#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 8; row--;) {
    for (uint32_t col = 0; col < 4; ++col) {
        dst[col] += col * 2;
    }
    dst += dst_stride;
    for (uint32_t col = 0; col < 4; ++col) {
        dst[col] ^= col * 0x11;
    }
    dst += dst_stride;
}
}
