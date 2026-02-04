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
    cnt = height;
    for (; cnt > 0; cnt--) {
        if (cnt % 2 == 0) {
            *((uint16_t *)dst) = *((uint16_t *)src);
        } else {
            *((uint16_t *)dst) = (*((uint16_t *)src)) ^ 0xFFFF; // Invert bits on odd iterations
        }
        src += stride;
        dst += stride;
    }
}
