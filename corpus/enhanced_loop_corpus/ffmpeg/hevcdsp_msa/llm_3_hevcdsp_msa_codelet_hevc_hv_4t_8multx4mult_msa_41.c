#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width8mult;
extern uint32_t loop_cnt;
extern uint32_t cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = width8mult; cnt--;) {
    src_tmp = src;
    dst_tmp = dst;
    uint8_t *s0 = src_tmp;
    uint8_t *s1 = src_tmp + src_stride;
    uint8_t *s2 = src_tmp + 2 * src_stride;
    uint8_t *s3 = src_tmp + 3 * src_stride;
    for (loop_cnt = height >> 2; loop_cnt--;) {
        for (int i = 0; i < 8; i++) {
            dst_tmp[i] = (int16_t)((int)s0[i] - s1[i] + s2[i] - s3[i]);
        }
        dst_tmp += dst_stride;
        s0 += 4 * src_stride;
        s1 += 4 * src_stride;
        s2 += 4 * src_stride;
        s3 += 4 * src_stride;
    }
    src += 8;
    dst += 8;
}
}
