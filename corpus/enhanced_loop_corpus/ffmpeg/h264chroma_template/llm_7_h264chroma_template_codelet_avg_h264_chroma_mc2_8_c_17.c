#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_dst0, local_dst1;
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < h; i++) {
        local_dst0 = local_dst[0];
        local_dst1 = local_dst[1];
        local_dst[0] = ((local_dst0 + (((A * local_src[0]) + 32) >> 6) + 1) >> 1);
        local_dst[1] = ((local_dst1 + (((A * local_src[1]) + 32) >> 6) + 1) >> 1);
        local_dst += stride;
        local_src += stride;
    }
}
