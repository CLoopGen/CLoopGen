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
    size_t idx = (size_t)row % 16;
    buffer[idx] = src[0];
    src += stride;
}
for (row = 16; row--;) {
    size_t idx = (size_t)row % 16;
    dst[0] = buffer[idx] ^ 0xFF;
    dst += stride;
}
}
