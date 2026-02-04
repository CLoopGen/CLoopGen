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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        const int32_t idx[4] = {0, src_stride, 2*src_stride, 3*src_stride};
        const int32_t dst_idx[4] = {0, dst_stride, 2*dst_stride, 3*dst_stride};

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                dst[dst_idx[i] + j] = (int16_t)src[idx[i] + j];
            }
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
