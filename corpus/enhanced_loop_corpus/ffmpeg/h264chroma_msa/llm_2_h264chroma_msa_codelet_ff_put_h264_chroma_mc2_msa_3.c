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
    for (cnt = 0; cnt < height; cnt++) {
        uint8_t *src_offset = src + cnt * stride;
        uint8_t *dst_offset = dst + cnt * stride;
        *((uint16_t *)dst_offset) = *((uint16_t *)src_offset);
    }
}
