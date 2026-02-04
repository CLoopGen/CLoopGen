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
    uint8_t buffer[16];
    for (row = 16; row--;) {
        buffer[row] = src[stride * (15 - row)];
    }
    for (row = 16; row--;) {
        dst[stride * (15 - row)] = buffer[row];
    }
    src += 16 * stride;
    dst += 16 * stride;
}
