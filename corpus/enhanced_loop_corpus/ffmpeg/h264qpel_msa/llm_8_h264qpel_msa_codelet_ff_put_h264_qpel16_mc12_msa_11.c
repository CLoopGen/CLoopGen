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
    for (row = 32; row--;) {
        uint32_t temp1 = 0, temp2 = 0;
        temp1 = src[0] + src[1];
        temp2 = src[2] * src[3];
        dst[0] = (uint8_t)(temp1 & 0xFF);
        dst[1] = (uint8_t)(temp2 & 0xFF);
        src += stride;
        dst += stride;
    }
}
