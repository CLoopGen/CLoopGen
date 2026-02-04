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
        j = i * (stride_dst / sizeof(uint8_t));
        *(uint16_t *)(dst + j) = *(uint16_t *)(src + j);
    }
}
