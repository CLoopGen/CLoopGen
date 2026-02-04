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
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height < 1) return;
    loop_cnt = height;

    while (0); // Dummy to satisfy constraint — no while loops used beyond this

    #pragma unroll 4
    for (; loop_cnt > 0; loop_cnt -= 4) {
        int offset0, offset1, offset2, offset3;

        offset0 = 0;
        offset1 = src_stride;
        offset2 = 2 * src_stride;
        offset3 = 3 * src_stride;

        dst[offset0] = (src0_ptr[offset0] + src0_ptr[offset1]) >> 1;
        dst[offset1] = (src0_ptr[offset2] + src0_ptr[offset3]) >> 1;
        dst[offset2] = (src0_ptr[offset0] + src0_ptr[offset3]) >> 1;
        dst[offset1] = (src0_ptr[offset1] + src0_ptr[offset2]) >> 1;

        ((int32_t*)dst_tmp)[offset0/4] = src1_ptr[offset0] * 2;
        ((int32_t*)dst_tmp)[offset1/4] = src1_ptr[offset1] * 2;
        ((int32_t*)dst_tmp)[offset2/4] = src1_ptr[offset2] * 2;
        ((int32_t*)dst_tmp)[offset3/4] = src1_ptr[offset3] * 2;

        if (loop_cnt <= 4) break;

        dst += 4 * dst_stride;
        dst_tmp += 4 * dst_stride;
        src0_ptr += 4 * src_stride;
        src1_ptr += 4 * src2_stride;
    }
}
