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
    uint32_t i, j;
    for (row = 8; row--;) {
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j) {
                dst[i * stride + j] = src[i * stride + j] + 1;
            }
        }
        src += stride * 4;
        dst += stride * 4;
    }
}
