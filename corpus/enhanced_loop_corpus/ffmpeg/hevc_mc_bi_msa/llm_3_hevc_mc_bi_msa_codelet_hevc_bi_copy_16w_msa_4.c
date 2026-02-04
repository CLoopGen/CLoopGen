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
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Strided access with increased stride simulation (every other row skipped)
    const int effective_stride = 2 * src_stride;
    const int effective_src2_stride = 2 * src2_stride;
    const int effective_dst_stride = 2 * dst_stride;

    for (int i = 0; i < 2; ++i) {
        uint8_t tmp0 = src0_ptr[i * effective_stride + 0];
        uint8_t tmp1 = src0_ptr[i * effective_stride + 1];
        uint8_t tmp2 = src0_ptr[i * effective_stride + 2];
        uint8_t tmp3 = src0_ptr[i * effective_stride + 3];

        int16_t val0 = src1_ptr[i * effective_src2_stride + 0];
        int16_t val1 = src1_ptr[i * effective_src2_stride + 1];

        dst[i * effective_dst_stride + 0] = tmp0 + (val0 & 0xFF);
        dst[i * effective_dst_stride + 1] = tmp1 + ((val0 >> 8) & 0xFF);
        dst[i * effective_dst_stride + 2] = tmp2 + (val1 & 0xFF);
        dst[i * effective_dst_stride + 3] = tmp3 + ((val1 >> 8) & 0xFF);
    }

    // Advance original pointers by full block (4 rows)
    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
