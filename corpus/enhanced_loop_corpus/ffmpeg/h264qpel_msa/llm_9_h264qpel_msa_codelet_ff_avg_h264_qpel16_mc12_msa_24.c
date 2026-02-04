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
    for (row = 32; row > 0; row -= 2) {
        dst[0] = src[0] + 10;
        dst[1] = src[1] + 20;
        dst[2] = src[2] + 30;
        dst[3] = src[3] + 40;

        src += stride / 2;
        dst += stride / 2;

        if (stride >= 8) {
            dst[0] ^= src[0];
            dst[1] ^= src[1];
        }

        src += stride / 2;
        dst += stride / 2;
    }
}
