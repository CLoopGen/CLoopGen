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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    const int32_t idx1 = 0;
    const int32_t idx2 = src_stride;
    const int32_t dst_idx1 = 0;
    const int32_t dst_idx2 = dst_stride;

    for (int offset = 0; offset < 32; offset += 4) {
        dst[dst_idx1 + offset + 0] = src[idx1 + offset + 0];
        dst[dst_idx1 + offset + 1] = src[idx1 + offset + 1];
        dst[dst_idx1 + offset + 2] = src[idx1 + offset + 2];
        dst[dst_idx1 + offset + 3] = src[idx1 + offset + 3];

        dst[dst_idx2 + offset + 0] = src[idx2 + offset + 0];
        dst[dst_idx2 + offset + 1] = src[idx2 + offset + 1];
        dst[dst_idx2 + offset + 2] = src[idx2 + offset + 2];
        dst[dst_idx2 + offset + 3] = src[idx2 + offset + 3];
    }

    src += (src_stride << 1);
    dst += (dst_stride << 1);
}
}
