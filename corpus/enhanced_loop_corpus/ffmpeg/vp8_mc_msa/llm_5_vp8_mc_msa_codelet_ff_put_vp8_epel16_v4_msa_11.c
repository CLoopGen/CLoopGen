#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t *src_temp = src;
        uint8_t *dst_temp = dst;
        if (loop_cnt & 1) {
            src_temp += (2 * src_stride);
            dst_temp += (2 * dst_stride);
        }
        src_temp += (2 * src_stride);
        dst_temp += (2 * dst_stride);
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
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        src = src_temp;
        dst = dst_temp;
    }
}
