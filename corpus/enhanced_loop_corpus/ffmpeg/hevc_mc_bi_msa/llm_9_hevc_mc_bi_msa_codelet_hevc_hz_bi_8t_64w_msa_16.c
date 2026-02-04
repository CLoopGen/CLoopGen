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
for (loop_cnt = height >> 2; loop_cnt--;) {
    int32_t j;
    for (j = 0; j < 4; ++j) {
        uint32_t offset = j * 16;
        int k;
        for (k = 0; k < 16; ++k) {
            int16_t val = src1_ptr[offset + k] + 32;
            uint8_t clamped = (val < 0) ? 0 : (val > 255) ? 255 : (uint8_t)val;
            dst[offset + k] = clamped ^ src0_ptr[offset + k];
        }
    }
    src1_ptr += src2_stride << 2;
    src0_ptr += src_stride << 2;
    dst += dst_stride << 2;
}
}
