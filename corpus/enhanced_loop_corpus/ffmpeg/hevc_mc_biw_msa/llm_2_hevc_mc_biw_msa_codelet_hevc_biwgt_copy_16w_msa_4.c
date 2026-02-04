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
    uint8_t *s0 = src0_ptr;
    int16_t *s1 = src1_ptr;
    uint8_t *d = dst;

    // Consecutive memory access with unrolled inner loop for better spatial locality
    for (int i = 0; i < 4; ++i) {
        d[0] = (uint8_t)((int)s0[0] + s1[0]);
        d[1] = (uint8_t)((int)s0[1] + s1[1]);
        d[2] = (uint8_t)((int)s0[2] + s1[2]);
        d[3] = (uint8_t)((int)s0[3] + s1[3]);

        s0 += src_stride;
        s1 += src2_stride;
        d += dst_stride;
    }

    src0_ptr += 4 * src_stride;
    src1_ptr += 4 * src2_stride;
    dst += 4 * dst_stride;
}
}
