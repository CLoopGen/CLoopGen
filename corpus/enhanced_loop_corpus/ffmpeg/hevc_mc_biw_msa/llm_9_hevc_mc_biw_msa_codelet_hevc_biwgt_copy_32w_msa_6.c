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
    if (height <= 0) return;

    uint32_t unroll_factor = 4;
    uint32_t adjusted_loop_cnt = height / unroll_factor;

    for (loop_cnt = 0; loop_cnt < adjusted_loop_cnt; loop_cnt++) {
        uint8_t *s0 = src0_ptr;
        int16_t *s1 = src1_ptr;
        uint8_t *d = dst;

        for (int inner = 0; inner < unroll_factor; inner += 2) {
            int offset = inner * src_stride;
            int offset16 = inner * src2_stride;
            int d_offset = inner * dst_stride;

            // Heavier computation: fused multiply-add and conditional logic simulation
            for (int j = 0; j < 16; j++) {
                uint32_t val8 = s0[offset + j];
                int32_t val16 = s1[offset16 + j];

                // Complex arithmetic expression with bit manipulation
                uint32_t expanded = (val8 << 3) | (val8 >> 5);
                int32_t processed = (val16 * 7 + expanded - 128) ^ 0xAA;

                d[d_offset + j] = (processed ^ (processed >> 8)) & 0xFF;
            }

            // Second row in pair
            for (int j = 0; j < 16; j++) {
                uint32_t val8_next = s0[offset + j + src_stride];
                int32_t val16_next = s1[offset16 + j + src2_stride];

                uint32_t expanded_next = (val8_next << 3) | (val8_next >> 5);
                int32_t processed_next = (val16_next * 7 + expanded_next - 128) ^ 0x55;

                d[d_offset + j + dst_stride] = (processed_next ^ (processed_next >> 8)) & 0xFF;
            }
        }

        src0_ptr += src_stride * unroll_factor;
        src1_ptr += src2_stride * unroll_factor;
        dst += dst_stride * unroll_factor;
    }

    // Handle remaining rows if height is not a multiple of unroll_factor
    for (int rem = height % unroll_factor; rem > 0; rem -= 2) {
        for (int j = 0; j < 16; j++) {
            dst[j] = src0_ptr[j] ^ ((src1_ptr[j] + 128) & 0xFF);
        }
        src0_ptr += src_stride;
        src1_ptr += src2_stride;
        dst += dst_stride;
        if (rem == 1) break;
    }
}
