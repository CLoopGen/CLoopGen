#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        {
        }
        ;
        if (!(loop_cnt % 3)) {
            {
            }
            ;
            {
            }
            ;
            src += (4 * src_stride);
        } else {
            {
            }
            ;
            dst += (4 * dst_stride);
            continue;
        }
        {
        }
        ;
        {
        }
        ;
        {
        }
        ;
        if (src != NULL && dst != NULL) {
            {
            }
            ;
            {
            }
            ;
            {
            }
            ;
        }
        {
        }
        ;
        if (dst_stride >= src_stride) {
            {
            }
            ;
        }
        {
        }
        ;
        dst += (4 * dst_stride);
    }
}
