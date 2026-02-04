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
        uint8_t val_src0_upper = src0_ptr[0];
        uint8_t val_src0_lower = src0_ptr[src_stride];
        uint8_t sum_src0 = val_src0_upper + val_src0_lower;

        int16_t val_src1_upper = src1_ptr[0];
        int16_t val_src1_lower = src1_ptr[src2_stride / sizeof(int16_t)];
        int16_t diff_src1 = val_src1_upper - val_src1_lower;

        src0_ptr += 2 * src_stride;
        src1_ptr += 2 * src2_stride;

        // Introduce artificial loop-carried dependency via static accumulator
        static uint8_t running_correction = 0;
        dst[0] = sum_src0 + running_correction;
        dst[dst_stride] = (diff_src1 + running_correction) & 0xFF;
        running_correction = (running_correction + sum_src0) % 128;

        dst += 2 * dst_stride;
    }
}
