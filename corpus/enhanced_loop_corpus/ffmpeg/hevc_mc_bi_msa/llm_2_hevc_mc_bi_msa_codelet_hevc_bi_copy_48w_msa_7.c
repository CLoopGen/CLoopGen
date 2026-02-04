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
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t *src0_1 = src0_ptr;
    uint8_t *src0_2 = src0_ptr + src_stride;
    int16_t *src1_1 = src1_ptr;
    int16_t *src1_2 = src1_ptr + src2_stride;
    uint8_t *dst_1 = dst;
    uint8_t *dst_2 = dst + dst_stride;

    // Access memory in consecutive pairs to improve spatial locality
    for (int i = 0; i < 2; ++i) {
        dst_1[i] = src0_1[i];
        dst_2[i] = src0_2[i];
    }

    src0_ptr += (src_stride << 1);
    src1_ptr += (src2_stride << 1);
    dst += (dst_stride << 1);
}
}
