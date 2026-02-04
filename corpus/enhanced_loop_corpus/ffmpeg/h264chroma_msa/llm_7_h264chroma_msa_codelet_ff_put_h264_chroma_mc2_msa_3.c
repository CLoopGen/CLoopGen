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
    uint16_t *prev_dst = NULL;
    for (cnt = height; cnt--;) {
        uint16_t val = *((uint16_t *)src);
        uint16_t *current_dst = (uint16_t *)dst;
        if (prev_dst) {
            *current_dst = *prev_dst + val;
        } else {
            *current_dst = val;
        }
        prev_dst = current_dst;
        src += stride;
        dst += stride;
    }
}
