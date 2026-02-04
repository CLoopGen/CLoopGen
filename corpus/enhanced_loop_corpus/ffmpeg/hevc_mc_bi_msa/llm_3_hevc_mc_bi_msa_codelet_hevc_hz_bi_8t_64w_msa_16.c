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
    ptrdiff_t idx;

    for (int j = 0; j < 4; ++j) {
        idx = (ptrdiff_t)(j * 2);

        if (idx < (ptrdiff_t)src_stride) {
            dst[j * 2] = src0_ptr[idx];
        }

        if (idx < (ptrdiff_t)src2_stride / sizeof(int16_t)) {
            dst[j * 2 + 1] = (uint8_t)(src1_ptr[idx] >> 8);
        }
    }

    for (int k = 0; k < 4; ++k) {
        idx = (ptrdiff_t)(k * 4);

        if (idx < (ptrdiff_t)src_stride) {
            dst[8 + k] = src0_ptr[idx];
        }
    }

    src1_ptr += src2_stride;
    src0_ptr += src_stride;
    dst += dst_stride;
}
}
