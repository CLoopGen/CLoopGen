#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 32; row--;) {
    dst[0] = dst[1] + dst[2];
    dst[4] ^= 0xFF;
    dst += dst_stride;
    dst[8] = dst[9] + dst[10];
    dst[12] ^= 0xAA;
    dst += dst_stride;
}
}
