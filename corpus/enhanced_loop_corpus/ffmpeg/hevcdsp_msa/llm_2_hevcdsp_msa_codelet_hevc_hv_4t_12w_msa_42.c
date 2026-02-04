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
            dst_tmp[0] = (int16_t)(src_tmp[0]);
            dst_tmp[1] = (int16_t)(src_tmp[1]);
            dst_tmp[2] = (int16_t)(src_tmp[2]);
            dst_tmp[3] = (int16_t)(src_tmp[3]);
        }
        ;
        src_tmp += (4 * src_stride);
        {
            dst_tmp[dst_stride] = (int16_t)(src_tmp[-(4 * src_stride) + src_stride]);
            dst_tmp[2*dst_stride] = (int16_t)(src_tmp[-(4 * src_stride) + 2*src_stride]);
            dst_tmp[3*dst_stride] = (int16_t)(src_tmp[-(4 * src_stride) + 3*src_stride]);
            dst_tmp[4*dst_stride] = (int16_t)(src_tmp[-(4 * src_stride) + 4*src_stride]);
        }
        ;
        dst_tmp += (4 * dst_stride);
    }
}
