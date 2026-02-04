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
extern uint8_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_accum[4];
    int32_t i, offset;

    for (loop_cnt = (height >> 1); loop_cnt--;) {
        offset = 0;
        local_accum[0] = 0;
        local_accum[1] = 0;
        local_accum[2] = 0;
        local_accum[3] = 0;

        for (i = 0; i < 2; ++i) {
            local_accum[offset]     = src0_ptr[i * src_stride + 0] + 10;
            local_accum[offset + 1] = src0_ptr[i * src_stride + 1] + 10;
            offset += 2;
        }

        dst[0] = local_accum[0];
        dst[1] = local_accum[1];
        dst[dst_stride] = local_accum[2];
        dst[dst_stride + 1] = local_accum[3];

        {
            int16_t val0 = src1_ptr[0];
            int16_t val1 = src1_ptr[1];
            int16_t val2 = src1_ptr[src2_stride];
            int16_t val3 = src1_ptr[src2_stride + 1];

            dst_tmp[0] = (val0 > 0) ? (uint8_t)(val0 & 0xFF) : 0;
            dst_tmp[1] = (val1 > 0) ? (uint8_t)(val1 & 0xFF) : 0;
            dst_tmp[dst_stride] = (val2 > 0) ? (uint8_t)(val2 & 0xFF) : 0;
            dst_tmp[dst_stride + 1] = (val3 > 0) ? (uint8_t)(val3 & 0xFF) : 0;
        }

        {
            dst[2] = dst[1] + 1;
            dst[dst_stride + 2] = dst[dst_stride + 1] + 1;
        }

        dst += (2 * dst_stride);
        src0_ptr += (2 * src_stride);
        src1_ptr += (2 * src2_stride);
        dst_tmp += (2 * dst_stride);
    }
}
