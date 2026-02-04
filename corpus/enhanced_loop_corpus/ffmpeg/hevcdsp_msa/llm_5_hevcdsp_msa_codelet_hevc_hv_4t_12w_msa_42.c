#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t src_stride;
extern int32_t dst_stride;
extern uint32_t loop_cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = 4; loop_cnt--;) {
        {
            if (src_stride > 1)
                src_tmp += (8 * src_stride);
            else
                src_tmp += (2 * src_stride);
        }
        {
            if (dst_stride < 3)
                dst_tmp += (6 * dst_stride);
            else
                dst_tmp += (2 * dst_stride);
        }
    }
}
