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
extern uint8_t *src_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src_tmp = src;
    dst_tmp = dst;

    int32_t row, col;
    for (row = 0; row < height; row += 4) {
        for (col = 0; col < 16; col += 4) {
            int32_t s_off = row * src_stride + col;
            int32_t d_off = row * dst_stride + col;

            ((uint32_t*)(&dst_tmp[d_off]))[0] = ((uint32_t*)(&src_tmp[s_off]))[0];
            ((uint32_t*)(&dst_tmp[d_off + dst_stride]))[0] = ((uint32_t*)(&src_tmp[s_off + src_stride]))[0];
            ((uint32_t*)(&dst_tmp[d_off + 2*dst_stride]))[0] = ((uint32_t*)(&src_tmp[s_off + 2*src_stride]))[0];
            ((uint32_t*)(&dst_tmp[d_off + 3*dst_stride]))[0] = ((uint32_t*)(&src_tmp[s_off + 3*src_stride]))[0];
        }
    }

    src += 16;
    dst += 16;
}
}
