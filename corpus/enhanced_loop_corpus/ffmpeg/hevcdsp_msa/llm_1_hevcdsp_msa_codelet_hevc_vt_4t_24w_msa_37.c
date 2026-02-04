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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 2; ++i) {
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
                dst += dst_stride;
                {
                }
                ;
                dst += dst_stride;
            }
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
            dst += (2 * dst_stride);
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
    }
}
