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
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const uint32_t indices[16] = {
        0, 4, 8, 12, 16, 20, 24, 28,
        32, 36, 40, 44, 48, 52, 56, 60
    };

    for (loop_cnt = 16; loop_cnt--;) {
        uint8_t sum = 0;
        for (int i = 0; i < 4; ++i) {
            uint32_t idx = indices[loop_cnt] + i;
            sum += src0_ptr[idx];
        }

        int32_t scaled = (int32_t)sum * src1_ptr[loop_cnt];
        dst[loop_cnt] = (uint8_t)(scaled & 0xFF);

        if ((loop_cnt & 3) == 0) {
            src0_ptr += src_stride;
            src1_ptr += src2_stride;
            dst += dst_stride;
        }
    }
}
