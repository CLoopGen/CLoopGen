#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src0_ptr_tmp;
extern int16_t *src1_ptr_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (width >> 3); cnt--;) {
    src0_ptr_tmp = src0_ptr;
    src1_ptr_tmp = src1_ptr;
    dst_tmp = dst;
    __builtin_prefetch(src0_ptr_tmp, 0, 3);
    __builtin_prefetch(src1_ptr_tmp, 0, 3);
    __builtin_prefetch(dst_tmp, 1, 3);
    for (loop_cnt = height; loop_cnt--;) {
        for (int w = 0; w < 8; w += 2) {
            int32_t s0 = src0_ptr_tmp[w];
            int32_t s1 = src1_ptr_tmp[w];
            int32_t result = (s0 * s1) + ((s0 + s1) >> 1);
            dst_tmp[w] = (result > 255) ? 255 : (result < 0 ? 0 : result);
        }
        src0_ptr_tmp += src_stride;
        src1_ptr_tmp += src2_stride;
        dst_tmp += dst_stride;
    }
    src0_ptr += 8;
    src1_ptr += 8;
    dst += 8;
}
}
