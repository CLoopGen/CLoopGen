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
        for (ptrdiff_t s = 0; s < stride; s++) {
            src[s] = dst[s];
        }
        src += stride;
        dst += stride;
    }
}
