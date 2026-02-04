#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height <= 0) return;
    int total_iters = height >> 2;
    for (int i = 0; i < total_iters; i++) {
        {
        }
        ;
        src += (2 * src_stride);
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
        {
        }
        ;
        dst += dst_stride;
        {
        }
        ;
        src += (2 * src_stride);
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
        {
        }
        ;
        dst += dst_stride;
    }
}
