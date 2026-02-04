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
    for (loop_cnt = height >> 2; loop_cnt--;) {
        dst_tmp[0] = (int16_t)(src_tmp[0 * src_stride] + src_tmp[1 * src_stride] + src_tmp[2 * src_stride] + src_tmp[3 * src_stride]);
        dst_tmp[1] = (int16_t)(src_tmp[4 * src_stride] + src_tmp[5 * src_stride] + src_tmp[6 * src_stride] + src_tmp[7 * src_stride]);
        dst_tmp += dst_stride;
        src_tmp += 8 * src_stride;
    }
    src += 8;
    dst += 8;
}
}
