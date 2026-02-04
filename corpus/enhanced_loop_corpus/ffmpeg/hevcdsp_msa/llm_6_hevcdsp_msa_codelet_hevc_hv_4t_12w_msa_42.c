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
    int32_t temp_accum = 0;
    for (loop_cnt = 4; loop_cnt--;) {
        temp_accum += src_tmp[0];
        temp_accum += src_tmp[src_stride];
        temp_accum += src_tmp[2 * src_stride];
        temp_accum += src_tmp[3 * src_stride];

        dst_tmp[0] = (int16_t)(temp_accum & 0xFFFF);
        dst_tmp[dst_stride] = (int16_t)((temp_accum >> 1) & 0xFFFF);

        src_tmp += (4 * src_stride);
        dst_tmp += (2 * dst_stride);
    }
    dst_tmp[-(8 * dst_stride)] = (int16_t)(temp_accum % 32768); // Introduce WAW and RAW dependency across iterations via loop-carried variable
}
