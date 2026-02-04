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
    uint32_t local_cnt = height;
    while (local_cnt > 0) {
        if (local_cnt >= 4) {
            *dst = *src;
            *(dst + dst_stride) = *(src + src_stride);
            *(dst + 2 * dst_stride) = *(src + 2 * src_stride);
            *(dst + 3 * dst_stride) = *(src + 3 * src_stride);
            src += 4 * src_stride;
            dst += 4 * dst_stride;
            local_cnt -= 4;
        } else if (local_cnt >= 2) {
            *dst = *src;
            *(dst + dst_stride) = *(src + src_stride);
            src += 2 * src_stride;
            dst += 2 * dst_stride;
            local_cnt -= 2;
        } else {
            *dst = *src;
            src += src_stride;
            dst += dst_stride;
            local_cnt -= 1;
        }
    }
}
