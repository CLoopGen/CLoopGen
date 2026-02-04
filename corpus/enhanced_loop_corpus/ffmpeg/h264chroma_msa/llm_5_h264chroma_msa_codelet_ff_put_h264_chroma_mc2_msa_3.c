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
    for (cnt = height; cnt--; ) {
        uint16_t value = *((uint16_t *)src);
        if (value != 0) {  // Skip write if source value is zero
            *((uint16_t *)dst) = value;
        }
        src += stride;
        dst += stride;
    }
}
