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
    int16_t temp_sum = 0;

    temp_sum += (int16_t)src[0 * src_stride];
    temp_sum += (int16_t)src[1 * src_stride];
    temp_sum += (int16_t)src[2 * src_stride];
    temp_sum += (int16_t)src[3 * src_stride];

    dst[0 * dst_stride] = temp_sum;
    dst[1 * dst_stride] = temp_sum >> 1;
    dst[2 * dst_stride] = temp_sum >> 2;
    dst[3 * dst_stride] = temp_sum >> 3;

    int32_t update_factor = (temp_sum & 0x3);

    for (int i = 0; i < 4; ++i) {
        dst[(i * dst_stride)] += update_factor * i;
    }

    src += (4 * src_stride);
    dst += (4 * dst_stride);
}
}
