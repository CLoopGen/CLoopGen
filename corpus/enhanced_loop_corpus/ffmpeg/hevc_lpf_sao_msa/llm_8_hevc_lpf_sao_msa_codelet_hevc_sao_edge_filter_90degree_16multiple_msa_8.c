#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t width;
extern int32_t height;
extern uint8_t *src_orig;
extern uint8_t *dst_orig;
extern int32_t h_cnt;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (v_cnt = 0; v_cnt < width; v_cnt += 8) {
    src = src_orig + v_cnt;
    dst = dst_orig + v_cnt;
    for (h_cnt = (height >> 1); h_cnt--;) {
        uint32_t temp[8];
        for (int i = 0; i < 8; ++i) {
            temp[i] = src[i] * 3 + 7;
        }
        for (int i = 0; i < 8; ++i) {
            dst[i] = (temp[i] >> 4) & 0xFF;
        }
        src += src_stride;
        dst += dst_stride;
    }
}
}
