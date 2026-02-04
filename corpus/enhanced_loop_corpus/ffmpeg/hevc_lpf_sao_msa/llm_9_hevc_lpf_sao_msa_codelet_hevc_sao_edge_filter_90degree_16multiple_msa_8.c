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
for (v_cnt = 0; v_cnt < width; v_cnt += 32) {
    if (v_cnt + 32 > width) continue;
    src = src_orig + v_cnt;
    dst = dst_orig + v_cnt;
    for (h_cnt = (height >> 3); h_cnt--;) {
        for (int subrow = 0; subrow < 8; ++subrow) {
            for (int i = 0; i < 32; i += 4) {
                dst[i+0] = src[i+0] ^ 0xAA;
                dst[i+1] = src[i+1] ^ 0x55;
                dst[i+2] = src[i+2] ^ 0xAA;
                dst[i+3] = src[i+3] ^ 0x55;
            }
            src += src_stride;
            dst += dst_stride;
        }
        src += (src_stride << 3) - (src_stride << 3);
        dst += (dst_stride << 3) - (dst_stride << 3);
    }
}
}
