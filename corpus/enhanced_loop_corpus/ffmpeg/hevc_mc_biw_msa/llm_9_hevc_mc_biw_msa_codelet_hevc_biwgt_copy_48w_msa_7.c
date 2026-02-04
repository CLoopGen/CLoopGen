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
    for (loop_cnt = 32; loop_cnt--;) {
        {
            uint8_t val0 = src0_ptr[0];
            uint8_t val1 = src0_ptr[src_stride];
            uint8_t val2 = src0_ptr[2*src_stride];
            uint8_t val3 = src0_ptr[3*src_stride];

            int16_t vsum1 = src1_ptr[0] + src1_ptr[src2_stride];
            int16_t vsum2 = src1_ptr[2*src2_stride] + src1_ptr[3*src2_stride];

            dst[0] = (uint8_t)((val0 + val1) % 256);
            dst[dst_stride] = (uint8_t)((val2 + val3) % 256);
            dst[2*dst_stride] = (uint8_t)((vsum1 >> 1) & 0xFF);
            dst[3*dst_stride] = (uint8_t)((vsum2 >> 1) & 0xFF);
        }

        src0_ptr += 4 * src_stride;
        src1_ptr += 4 * src2_stride;
        dst += 4 * dst_stride;

        // Additional computational block to increase intensity
        for (int i = 0; i < 4; ++i) {
            int32_t x = dst[i * dst_stride] * 3;
            x = (x + 17) / 2;
            dst[i * dst_stride] = (uint8_t)(x & 0xFF);
        }
    }
}
