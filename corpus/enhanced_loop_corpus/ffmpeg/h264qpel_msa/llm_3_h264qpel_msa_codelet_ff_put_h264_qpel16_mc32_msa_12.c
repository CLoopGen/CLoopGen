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
ptrdiff_t index = 0;
for (row = 16; row--;) {
    for (uint32_t offset = 0; offset < 16; offset += 4) {
        dst[index + offset + 0] = src[index + (offset * 3) % 64];
        dst[index + offset + 1] = src[index + ((offset + 1) * 3) % 64];
        dst[index + offset + 2] = src[index + ((offset + 2) * 3) % 64];
        dst[index + offset + 3] = src[index + ((offset + 3) * 3) % 64];
    }
    index += stride;
    src += stride;
    dst += stride;
}
}
