#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t height;
extern uint32_t loop_cnt;
extern uint8_t *src0_ptr;
extern int32_t src_stride;
extern int16_t *src1_ptr;
extern int32_t src2_stride;
extern uint8_t *dst;
extern int32_t dst_stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height == 0) return;
    
    loop_cnt = height;
    do {
        uint8_t val0 = *src0_ptr;
        uint8_t val1 = *(src0_ptr + src_stride - 1);
        int16_t val2 = *src1_ptr;
        int16_t val3 = *(src1_ptr + src2_stride - 1);

        uint32_t combined = (val0 + val1) * (val2 - val3);
        *dst = (uint8_t)(combined & 0xFF);
        *(dst + 1) = (uint8_t)((combined >> 8) & 0xFF);

        src0_ptr += src_stride << 1;
        src1_ptr += src2_stride << 1;
        dst += dst_stride << 1;
        loop_cnt--;
    } while (loop_cnt > 0);
}
