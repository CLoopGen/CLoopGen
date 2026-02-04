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
    int32_t i;
    uint8_t *src_local[4];
    int16_t *dst_local[4];

    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (i = 0; i < 4; i++) {
            src_local[i] = &src[i * src_stride];
            dst_local[i] = &dst[i * dst_stride];
        }

        for (i = 0; i < 4; i++) {
            dst_local[i][0] = (int16_t)src_local[i][0];
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
        dst_tmp += (4 * dst_stride);
    }
}
