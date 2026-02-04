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
    uint16_t temp;
    for (cnt = height; cnt--;) {
        temp = *((uint16_t *)src);
        *((uint16_t *)dst) = temp;
        src += stride;
        dst += stride;
    }
}
