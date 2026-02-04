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
        // Variant 2: Strided memory access with alternating offset pattern
        int32_t effective_stride = src_stride * 2;
        int32_t s2_stride = src2_stride * 2;
        int32_t d_stride = dst_stride * 2;

        // Access elements at increasing offsets with fixed stride step
        for (int k = 0; k < 4; k++) {
            int idx = k * 4;

            // Strided read from src0 (byte) and src1 (int16)
            uint8_t val0 = *(src0_ptr + idx * src_stride);
            uint8_t val1 = *(src0_ptr + src_stride + idx * src_stride);
            int16_t sval0 = *(src1_ptr + idx * src2_stride);
            int16_t sval1 = *(src1_ptr + src2_stride + idx * src2_stride);

            // Write to destination with strided pattern
            *(dst + idx * dst_stride) = (uint8_t)(sval0 > 0 ? sval0 & 0xFF : ~sval0);
            *(dst + dst_stride + idx * dst_stride) = (uint8_t)(sval1 < 0 ? -sval1 : sval1 >> 8);
        }

        // Global pointer advancement
        src0_ptr += effective_stride;
        src1_ptr += s2_stride;
        dst += d_stride;
    }
}
