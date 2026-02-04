#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 16; row--;) {
    uint8_t temp1 = src[0];
    uint8_t temp2 = src[1];
    dst[0] = temp1 ^ temp2;
    dst[1] = temp2 ^ 0xFF;
    src += stride;
    dst += stride;
}
}
