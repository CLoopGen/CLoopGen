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
extern uint8_t *src0_ptr_tmp;
extern uint8_t *dst_tmp;
extern int16_t *src1_ptr_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = height >> 1; loop_cnt--;) {
    src0_ptr_tmp = src0_ptr;
    dst_tmp = dst;
    src1_ptr_tmp = src1_ptr;
    for (cnt = 1; cnt--;) {
        uint32_t i;
        for (i = 0; i < 64; ++i) {
            uint8_t a = src0_ptr_tmp[i * 2];
            uint8_t b = src0_ptr_tmp[i * 2 + 1];
            int16_t c = src1_ptr_tmp[i];
            uint16_t product = (a * b) >> c;
            dst_tmp[i] = (product > 255) ? 255 : product;
        }
        src0_ptr_tmp += 128;
        src1_ptr_tmp += 64;
        dst_tmp += 64;
    }
    src0_ptr += src_stride << 1;
    src1_ptr += src2_stride << 1;
    dst += dst_stride << 1;
}
}
