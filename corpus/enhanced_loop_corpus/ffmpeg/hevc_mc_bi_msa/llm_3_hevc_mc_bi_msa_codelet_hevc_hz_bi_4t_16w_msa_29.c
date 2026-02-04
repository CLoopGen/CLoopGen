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
    // Change memory access to indirect indexing using fixed offsets
    const int32_t idx0 = 0;
    const int32_t idx1 = src_stride;
    const int32_t src_idx0 = 0;
    const int32_t src_idx1 = src2_stride;
    const int32_t dst_idx0 = 0;
    const int32_t dst_idx1 = dst_stride;

    // Simulate strided but unrolled-by-2 write with direct loads via pointer arithmetic
    uint8_t val0_0 = *(src0_ptr + idx0);
    uint8_t val0_1 = *(src0_ptr + idx1);
    uint8_t val1_0 = *((uint8_t*)src1_ptr + src_idx0);
    uint8_t val1_1 = *((uint8_t*)src1_ptr + src_idx1);

    *(dst + dst_idx0) = (val0_0 & 0x7F) + (val1_0 >> 2);
    *(dst + dst_idx1) = (val0_1 & 0x7F) + (val1_1 >> 2);

    // Update pointers with stride for next two rows
    src0_ptr += (2 * src_stride);
    src1_ptr += (2 * src2_stride);
    dst += (2 * dst_stride);
}
}
