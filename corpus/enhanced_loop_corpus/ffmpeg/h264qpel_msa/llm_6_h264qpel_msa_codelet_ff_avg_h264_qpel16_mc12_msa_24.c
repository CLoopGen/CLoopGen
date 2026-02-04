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
    uint32_t temp __attribute__((unused));
    for (row = 16; row--;) {
        temp = src[0];
        dst[0] = temp;
        src += stride;
        dst += stride;
    }
}
