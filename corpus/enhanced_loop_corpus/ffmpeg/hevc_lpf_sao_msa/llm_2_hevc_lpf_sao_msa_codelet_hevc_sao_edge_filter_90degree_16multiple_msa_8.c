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
for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
    src = src_orig + v_cnt;
    dst = dst_orig + v_cnt;
    for (h_cnt = (height >> 2); h_cnt--;) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 16; ++j) {
                dst[j + i * dst_stride] = src[j + i * src_stride];
            }
        }
        src += (src_stride << 2);
        dst += (dst_stride << 2);
    }
}
}
