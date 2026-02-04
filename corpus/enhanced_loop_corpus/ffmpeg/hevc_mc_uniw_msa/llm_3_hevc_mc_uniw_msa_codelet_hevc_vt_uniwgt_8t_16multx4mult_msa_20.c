#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t weightmul16;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = weightmul16; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    src_tmp += (7 * src_stride);
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Change memory access pattern: use strided access with offset array indexing
        int32_t offsets[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; ++i) {
            int32_t src_idx = offsets[i] * src_stride;
            int32_t dst_idx = offsets[i] * dst_stride;
            dst_tmp[dst_idx] = src_tmp[src_idx];
        }

        src_tmp += (4 * src_stride);
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
