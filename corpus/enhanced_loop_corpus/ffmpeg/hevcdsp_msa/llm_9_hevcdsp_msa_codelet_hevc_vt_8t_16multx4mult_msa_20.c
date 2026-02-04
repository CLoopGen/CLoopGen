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
for (cnt = width >> 5; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        dst_tmp[0] = (int16_t)((src_tmp[0] * 3 + src_tmp[src_stride] * 2 + src_tmp[2*src_stride] * 3 + src_tmp[3*src_stride]) >> 3);
        dst_tmp[1] = (int16_t)((src_tmp[1] * 3 + src_tmp[1 + src_stride] * 2 + src_tmp[1 + 2*src_stride] * 3 + src_tmp[1 + 3*src_stride]) >> 3);
        dst_tmp[dst_stride] = (int16_t)((src_tmp[src_stride] * 3 + src_tmp[2*src_stride] * 2 + src_tmp[3*src_stride] * 3 + src_tmp[4*src_stride]) >> 3);
        dst_tmp[1 + dst_stride] = (int16_t)((src_tmp[1 + src_stride] * 3 + src_tmp[1 + 2*src_stride] * 2 + src_tmp[1 + 3*src_stride] * 3 + src_tmp[1 + 4*src_stride]) >> 3);
        dst_tmp += (2 * dst_stride);
        src_tmp += (4 * src_stride);
    }
    src += 32;
    dst += 32;
}
}
