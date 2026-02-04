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
extern int32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 2); loop_cnt--;) {
    // Variant 1: Consecutive memory access with linear increment and reduced stride jumps
    // Instead of jumping by 2*stride every time, process 4 rows consecutively with unit stride in small blocks

    for (int row = 0; row < 4; row++) {
        uint8_t *src0_row = src0_ptr + row * src_stride;
        int16_t *src1_row = src1_ptr + row * src2_stride;
        uint8_t *dst_row = dst + row * dst_stride;

        // Simulate processing: copy 4 pixels with consecutive access
        for (int col = 0; col < 4; col++) {
            int16_t temp = (int16_t)src0_row[col] + src1_row[col];
            dst_row[col] = (temp > 255) ? 255 : (temp < 0) ? 0 : (uint8_t)temp;
        }
    }

    // Advance pointers by total block height
    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
