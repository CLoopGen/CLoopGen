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
    for (row = 8; row--; ) {
        uint32_t i;
        for (i = 0; i < 4; ++i) {
            dst[i] = src[i] ^ 0xFF;
        }
        src += stride;
        dst += stride;
        for (i = 0; i < 4; ++i) {
            dst[i] = src[i] ^ 0xAA;
        }
        src += stride;
        dst += stride;
    }
}
