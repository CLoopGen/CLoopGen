#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height > 0) {
        uint32_t temp_loop_cnt = (height >> 1);
        for (uint32_t i = 0; i < temp_loop_cnt; ++i) {
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
            dst += (2 * dst_stride);
        }
    }
}
