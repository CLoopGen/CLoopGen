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
    for (cnt = height; cnt--;) {
        for (int inner = 0; inner < 1; inner++) {
            *((uint16_t *)dst) = *((uint16_t *)src);
            src += stride;
            dst += stride;
        }
    }
}
