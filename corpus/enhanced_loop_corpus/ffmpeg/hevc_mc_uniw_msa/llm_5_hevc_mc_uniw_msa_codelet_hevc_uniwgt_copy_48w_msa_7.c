#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt-- > 0;) {
        src += src_stride;
        src += src_stride;

        {
            uint32_t step = (loop_cnt & 1) ? 1 : 2;
            for (int i = 0; i < step; ++i) {
                dst += dst_stride;
            }
        }

        {
            const int update_flag = (loop_cnt > (height >> 3));
            if (update_flag) {
                src += src_stride;
            }
        }
    }
}
