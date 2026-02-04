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
    int32_t i;
    uint8_t *src_ptr = src;
    int16_t *dst_ptr = dst;

    for (i = 0; i < 8; ++i) {
        dst_ptr[0] = (int16_t)src_ptr[0];
        dst_ptr[1] = (int16_t)src_ptr[1];
        dst_ptr[2] = (int16_t)src_ptr[2];
        dst_ptr[3] = (int16_t)src_ptr[3];
        dst_ptr[4] = (int16_t)src_ptr[4];
        dst_ptr[5] = (int16_t)src_ptr[5];
        dst_ptr[6] = (int16_t)src_ptr[6];
        dst_ptr[7] = (int16_t)src_ptr[7];

        src_ptr += src_stride;
        dst_ptr += dst_stride;
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
