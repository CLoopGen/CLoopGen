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
    int outer = height / 2;
    int remainder = height % 2;
    for (i = 0; i < outer; i++) {
        *(uint16_t *)dst = *(uint16_t *)src;
        dst += stride_dst;
        src += stride_src;
        *(uint16_t *)dst = *(uint16_t *)src;
        dst += stride_dst;
        src += stride_src;
    }
    for (i = 0; i < remainder; i++) {
        *(uint16_t *)dst = *(uint16_t *)src;
        dst += stride_dst;
        src += stride_src;
    }
}
