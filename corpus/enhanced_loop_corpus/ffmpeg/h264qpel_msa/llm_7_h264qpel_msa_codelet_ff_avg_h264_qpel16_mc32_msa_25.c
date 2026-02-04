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
    ptrdiff_t offset = (row & 7) * 2;
    buffer[row] = src[offset] + src[offset + 1];
}
for (row = 16; row--;) {
    dst[row] = buffer[row] ^ 0x55;
    dst[stride + row] = buffer[(15 - row)] ^ 0xAA;
}
src += stride * 16;
dst += stride * 16;
}
