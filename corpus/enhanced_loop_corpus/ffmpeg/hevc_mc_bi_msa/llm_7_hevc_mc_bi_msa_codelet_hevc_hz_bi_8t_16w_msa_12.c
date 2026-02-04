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
int32_t offset_src0 = 0;
int32_t offset_src1 = 0;
int32_t offset_dst = 0;

for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t s0_0 = src0_ptr[offset_src0];
    uint8_t s0_1 = src0_ptr[offset_src0 + src_stride];
    uint8_t s0_2 = src0_ptr[offset_src0 + 2*src_stride];
    uint8_t s0_3 = src0_ptr[offset_src0 + 3*src_stride];

    int16_t s1_0 = src1_ptr[offset_src1];
    int16_t s1_1 = src1_ptr[offset_src1 + src2_stride];
    int16_t s1_2 = src1_ptr[offset_src1 + 2*src2_stride];
    int16_t s1_3 = src1_ptr[offset_src1 + 3*src2_stride];

    uint8_t combined_val = (uint8_t)(
        (s0_0 + s0_1 + s1_0 + s1_1) / 4
    );
    dst[offset_dst] = combined_val;

    uint8_t derived_val = (uint8_t)(
        (s0_2 + s0_3 + s1_2 + s1_3) / 4
    );
    dst[offset_dst + dst_stride] = derived_val;

    offset_src0 += 2 * src_stride;
    offset_src1 += 2 * src2_stride;
    offset_dst += 2 * dst_stride;
}
}
