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
extern uint8_t *dst_ptr;
extern uint8_t *src_minus1;
extern int32_t v_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; height; height -= 4) {
    src_minus1 = src - 1;
    for (v_cnt = 0; v_cnt < width; v_cnt += 16) {
        src_minus1 += 16;
        dst_ptr = dst + v_cnt;
        // Simulate consecutive memory access by unrolling and accessing adjacent elements
        for (int k = 0; k < 16; k += 4) {
            dst_ptr[k + 0] = src_minus1[k + 0];
            dst_ptr[k + 1] = src_minus1[k + 1];
            dst_ptr[k + 2] = src_minus1[k + 2];
            dst_ptr[k + 3] = src_minus1[k + 3];
        }
    }
    src += (src_stride << 2);
    dst += (dst_stride << 2);
}
}
