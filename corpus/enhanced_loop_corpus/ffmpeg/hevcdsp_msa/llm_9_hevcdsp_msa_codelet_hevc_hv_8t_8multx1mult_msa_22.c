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
extern uint32_t loop_cnt;
extern uint32_t cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (width >> 4); cnt--;) {
        src_tmp = src;
        dst_tmp = dst;
        for (loop_cnt = height >> 1; loop_cnt--;) {
            for (int k = 0; k < 8; k++) {
                dst_tmp[k] = (int16_t)(src_tmp[k] * 2 - 128);
            }
            src_tmp += src_stride;
            dst_tmp += dst_stride;
            for (int k = 0; k < 8; k++) {
                dst_tmp[k] = (int16_t)(src_tmp[k] * 2 - 128);
            }
            src_tmp += src_stride;
            dst_tmp += dst_stride;
        }
        src += 16;
        dst += 16;
    }
}
