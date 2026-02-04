#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = 4; loop_cnt--;) {
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    src += (4 * stride);
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
        dst[2] = src[2 * stride];
        dst[3] = src[3 * stride];
    }
    ;
    {
        dst[0] = src[0];
    }
    ;
    {
        dst[1] = src[stride];
    }
    ;
    {
        dst[0] = src[0];
        dst[1] = src[stride];
    }
    ;
    dst += (4 * stride);
}
}
