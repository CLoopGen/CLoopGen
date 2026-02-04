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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    ptrdiff_t s_dst = stride_dst;
    ptrdiff_t s_src = stride_src;
    int h = height;
    for (i = 0; i < h; i++) {
        local_dst[0] = local_src[0];
        local_dst += s_dst;
        local_src += s_src;
    }
    dst = local_dst;
    src = local_src;
}
