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
    for (loop_cnt = height; loop_cnt--;) {
        uint32_t inner_loop = 4;
        while (inner_loop--) {
            int16_t temp0 = *src1_ptr;
            int16_t temp1 = *(src1_ptr + 1);
            int32_t sum = temp0 + temp1;
            uint8_t val = (uint8_t)((sum >> 1) & 0xFF);
            *dst = val;
            dst++;
            src1_ptr += 2;
        }
        src0_ptr += src_stride;
        src1_ptr += src2_stride - 8; // adjust back offset after inner stepping
        dst += dst_stride - 4;
    }
}
