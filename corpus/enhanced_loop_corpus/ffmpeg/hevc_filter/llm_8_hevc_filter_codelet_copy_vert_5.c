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
    int j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < 2; j++) {
            *(uint16_t *)(dst + j * 2) = *(uint16_t *)(src + j * 2);
        }
        dst += stride_dst;
        src += stride_src;
    }
}
