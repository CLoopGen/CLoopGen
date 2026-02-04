#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 4; loop_cnt--;) {
    uint8_t *local_src = src;
    uint8_t *local_dst = dst;
    local_dst[0] = local_src[0];
    local_dst[1] = local_src[1];
    local_dst[2] = local_src[2];
    local_dst[3] = local_src[3];
    src += stride;
    dst += stride;
    {
        {
            dst[0] = src[0];
        }
        ;
        {
            src += stride;
        }
        ;
    }
    ;
    {
        {
            dst[1] = src[-1];
        }
        ;
        {
            src += stride;
        }
        ;
    }
    ;
    {
        {
            dst[2] = src[-2];
        }
        ;
        {
            src += stride;
        }
        ;
    }
    ;
    dst += (stride + 3);
}
}
