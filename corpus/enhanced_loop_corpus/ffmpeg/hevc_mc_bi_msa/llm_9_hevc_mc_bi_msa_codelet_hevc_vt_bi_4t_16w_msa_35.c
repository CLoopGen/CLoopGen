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
for (loop_cnt = (height >> 3); loop_cnt--;) {
    for (int inner = 0; inner < 4; inner++) {
        {
            uint8_t val0 = src0_ptr[inner * 4 + 0];
            uint8_t val1 = src0_ptr[inner * 4 + 1];
            uint8_t val2 = src0_ptr[inner * 4 + 2];
            uint8_t val3 = src0_ptr[inner * 4 + 3];
            int16_t sum = val0 + val1 + val2 + val3;
            dst[inner * 2 + 0] = (uint8_t)(sum >> 2);
            dst[inner * 2 + 1] = (uint8_t)((sum * 3) >> 3);
        }

        int16_t v0 = src1_ptr[inner * 2 + 0];
        int16_t v1 = src1_ptr[inner * 2 + 1];
        dst[inner * 4 + 0] ^= (uint8_t)(v0 & 0xFF);
        dst[inner * 4 + 2] ^= (uint8_t)(v1 & 0xFF);
    }
    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
