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
    if (height <= 0) return;

    // Unroll by factor of 1 and increase computational intensity per iteration
    for (loop_cnt = height; loop_cnt--;) {
        uint8_t val_src0 = *src0_ptr;
        uint8_t next_src0 = *(src0_ptr + src_stride);
        int16_t val_src1 = *src1_ptr;
        int16_t next_src1 = *(src1_ptr + src2_stride);

        // Perform multiple arithmetic operations: add, shift, XOR, saturate
        int32_t combined0 = ((val_src0 + val_src1) << 1) ^ 0x5A;
        int32_t combined1 = ((next_src0 + next_src1) << 1) ^ 0x5A;

        // Saturate to 8-bit range
        combined0 = (combined0 < 0) ? 0 : (combined0 > 255 ? 255 : combined0);
        combined1 = (combined1 < 0) ? 0 : (combined1 > 255 ? 255 : combined1);

        *dst = (uint8_t)combined0;
        *(dst + dst_stride) = (uint8_t)combined1;

        *dst_tmp = (uint8_t)(combined0 ^ 0xFF);
        *(dst_tmp + dst_stride) = (uint8_t)(combined1 ^ 0xFF);

        // Update pointers once per full row processing
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
        dst_tmp += dst_stride;
    }
}
