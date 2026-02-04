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
    for (loop_cnt = 8; loop_cnt--;) {
        int32_t offset_src = 2 * src_stride;
        int32_t offset_dst = 2 * dst_stride;

        // Perform multiple updates per iteration to increase computational load
        for (int i = 0; i < 2; ++i) {
            src_tmp += offset_src;
            dst_tmp += offset_dst;
            
            // Simulate some computation: write scaled values
            for (int j = 0; j < 4; ++j) {
                dst_tmp[j] = (int16_t)(src_tmp[j] * 2 + 1);
            }
        }

        // Additional arithmetic to increase intensity
        src_tmp += src_stride;
        dst_tmp += dst_stride;
    }
}
