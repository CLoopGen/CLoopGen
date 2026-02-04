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
        int32_t offset_dst = 0;
        int32_t offset_src0 = 0;
        int32_t offset_src1 = 0;

        uint8_t val_src0_upper = src0_ptr[offset_src0];
        uint8_t val_src0_lower = src0_ptr[offset_src0 + src_stride];
        int16_t val_src1_upper = src1_ptr[offset_src1];
        int16_t val_src1_lower = src1_ptr[offset_src1 + src2_stride];

        uint8_t sum_upper = (uint8_t)(val_src0_upper + val_src1_upper);
        uint8_t sum_lower = (uint8_t)(val_src0_lower + val_src1_lower);

        dst[offset_dst] = sum_upper;
        dst[offset_dst + dst_stride] = sum_lower;

        offset_src0 += 2 * src_stride;
        offset_src1 += 2 * src2_stride;
        offset_dst += 2 * dst_stride;

        src0_ptr += offset_src0;
        src1_ptr += offset_src1;
        dst += offset_dst;
    }
}
