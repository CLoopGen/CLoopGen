#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < height / 2; outer++) {
        *((uint16_t *)dst) = *((uint16_t *)src);
        src += stride;
        dst += stride;
        *((uint16_t *)dst) = *((uint16_t *)src);
        src += stride;
        dst += stride;
    }
    if (height % 2) {
        *((uint16_t *)dst) = *((uint16_t *)src);
        src += stride;
        dst += stride;
    }
}
