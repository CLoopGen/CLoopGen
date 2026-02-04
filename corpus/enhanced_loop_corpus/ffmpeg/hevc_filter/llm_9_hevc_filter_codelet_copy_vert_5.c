#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i += 2) {
        if (i + 1 < height) {
            *(uint16_t *)dst = *(uint16_t *)src;
            dst += stride_dst;
            src += stride_src;
            *(uint16_t *)dst = *(uint16_t *)src;
            dst += stride_dst;
            src += stride_src;
        } else {
            *(uint16_t *)dst = *(uint16_t *)src;
        }
    }
}
