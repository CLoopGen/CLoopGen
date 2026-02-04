#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_cache[2] = {0};
    for (loop_cnt = height; loop_cnt--;) {
        {
            local_cache[0] = src[0] + 1;
            local_cache[1] = src[1] + 2;
        }
        ;
        {
            dst[0] = local_cache[0];
            dst[1] = local_cache[1];
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        src += src_stride;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        dst += dst_stride;
    }
}
