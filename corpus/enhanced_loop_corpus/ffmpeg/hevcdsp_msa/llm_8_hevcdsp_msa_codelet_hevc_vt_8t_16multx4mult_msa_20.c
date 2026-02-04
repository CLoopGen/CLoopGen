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
for (cnt = width >> 3; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        dst_tmp[0] = (int16_t)(src_tmp[0] << 2) - 32;
        dst_tmp[1] = (int16_t)(src_tmp[1] << 2) - 32;
        dst_tmp[2] = (int16_t)(src_tmp[2] << 2) - 32;
        dst_tmp[3] = (int16_t)(src_tmp[3] << 2) - 32;
        dst_tmp += dst_stride;
        src_tmp += src_stride;
    }
    src += 8;
    dst += 8;
}
}
