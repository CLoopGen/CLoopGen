#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height / 8); cnt--;) {
        for (int i = 0; i < 2; ++i) {
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            if (i == 0) {
                src += (4 * src_stride);
                dst_dup += (4 * dst_stride);
            } else {
                src += (4 * src_stride);
                dst += (4 * dst_stride);
            }
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                {
                }
            }
            ;
            {
                {
                }
                {
                }
            }
            ;
            {
                {
                }
                {
                }
            }
            ;
            {
                {
                }
                {
                }
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            {
                {
                }
                ;
                {
                }
                ;
            }
            ;
            if (i == 0) {
                dst_dup += (4 * dst_stride);
            } else {
                dst += (4 * dst_stride);
            }
        }
    }
}
