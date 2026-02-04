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
    for (row = 8; row--;) {
        for (uint32_t col = 0; col < 4; ++col) {
            dst[col + 0] = src[col + 0] ^ 0xAA;
            dst[col + 4] = src[col + 4] ^ 0x55;
        }
        src += stride;
        dst += stride;
    }
}
