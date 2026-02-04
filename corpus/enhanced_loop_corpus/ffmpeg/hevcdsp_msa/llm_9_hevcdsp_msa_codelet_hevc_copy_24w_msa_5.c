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
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        for (int i = 0; i < 8; i += 2) {
            int32_t src_idx1 = i * src_stride;
            int32_t src_idx2 = (i + 1) * src_stride;
            int32_t dst_idx1 = i * dst_stride;
            int32_t dst_idx2 = (i + 1) * dst_stride;

            int32_t sum1 = (int32_t)src[src_idx1] + src[src_idx1 + 1];
            int32_t sum2 = (int32_t)src[src_idx2] + src[src_idx2 + 1];

            dst[dst_idx1] = (int16_t)((sum1 << 1) - 512);
            dst[dst_idx1 + 1] = (int16_t)(sum1 * 3);
            dst[dst_idx2] = (int16_t)((sum2 << 1) - 512);
            dst[dst_idx2 + 1] = (int16_t)(sum2 * 3);
        }
        src += (8 * src_stride);
        dst += (8 * dst_stride);
    }
}
