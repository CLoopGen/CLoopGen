#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = width >> 4; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    int32_t offset = 0;
    for (int i = 0; i < 4; ++i) {
        ((int32_t*)dst_tmp)[i * (dst_stride / 2)] = 0;
    }
    src_tmp += (7 * src_stride);
    int16_t prev_write = 0;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        int16_t new_val = (int16_t)(src_tmp[0] + src_tmp[2] + src_tmp[4] + src_tmp[6]);
        dst_tmp[0] = new_val;
        dst_tmp[dst_stride] = new_val ^ prev_write;
        dst_tmp[2*dst_stride] = prev_write + src_tmp[1];
        dst_tmp[3*dst_stride] = prev_write - src_tmp[3];
        prev_write = new_val;
        src_tmp += (4 * src_stride);
        dst_tmp += (4 * dst_stride);
    }
    src += 16;
    dst += 16;
}
}
