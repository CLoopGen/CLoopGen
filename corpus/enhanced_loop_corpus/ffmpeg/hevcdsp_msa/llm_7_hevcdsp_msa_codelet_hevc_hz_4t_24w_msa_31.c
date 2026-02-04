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
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t s0 = src[0];
        uint8_t s1 = src[src_stride];
        uint8_t s2 = src[2 * src_stride];
        uint8_t s3 = src[3 * src_stride];

        int16_t temp_val = (int16_t)(s0 + s1 + s2 + s3);

        dst[0] = temp_val;
        dst[dst_stride] = temp_val;
        dst[2 * dst_stride] = temp_val;
        dst[3 * dst_stride] = temp_val;

        dst_tmp[0] = temp_val + 1;
        dst_tmp[dst_stride] = temp_val + 2;
        dst_tmp[2 * dst_stride] = temp_val + 3;
        dst_tmp[3 * dst_stride] = temp_val + 4;

        src += 4 * src_stride;
        dst += 4 * dst_stride;
        dst_tmp += 4 * dst_stride;
    }
}
