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
        for (int i = 0; i < 4; ++i) {
            uint8_t temp = 0;
            for (int j = 0; j < 4; ++j) {
                temp ^= src0_ptr[j];
            }
            dst[i * 4] = temp;

            int16_t accum = 0;
            for (int k = 0; k < 8; ++k) {
                accum += src1_ptr[k];
            }
            ((int16_t*)dst)[i * 2] = accum;

            src0_ptr += src_stride;
            src1_ptr += src2_stride;
        }
        dst += 4 * dst_stride;
    }
}
