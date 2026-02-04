#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern int32_t cnt;
extern int32_t loop_cnt;
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    for (loop_cnt = (height >> 3); loop_cnt--;) {
        int32_t row_offset_src_base = loop_cnt * 8 * src_stride;
        int32_t row_offset_dst_base = loop_cnt * 8 * dst_stride;
        uint8_t *src_block = src + row_offset_src_base;
        uint8_t *dst_block = dst + row_offset_dst_base;

        for (int i = 0; i < 8; ++i) {
            uint8_t *s = src_block + i * src_stride;
            uint8_t *d = dst_block + i * dst_stride;
            for (int j = 0; j < 16; j += 4) {
                d[j+0] = s[j+0];
                d[j+1] = s[j+1];
                d[j+2] = s[j+2];
                d[j+3] = s[j+3];
            }
        }
    }
    src += 16;
    dst += 16;
}
}
