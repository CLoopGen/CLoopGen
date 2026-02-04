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
    uint8_t temp_src0;
    int16_t temp_src1;
    for (loop_cnt = height; loop_cnt--;) {
        temp_src0 = *src0_ptr;
        temp_src1 = *src1_ptr;

        // Introduce artificial dependency: use temp_src0 to influence temp_src1 usage
        if (temp_src0 > 127) {
            temp_src1 += 10;
        } else {
            temp_src1 -= 5;
        }

        // Write modified value back through dst with data-dependent store
        *dst = (uint8_t)(temp_src1 & 0xFF);

        // Update pointers with stride
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
    }
}
