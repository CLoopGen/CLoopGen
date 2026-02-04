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
extern int32_t width;
extern uint8_t *src0_ptr_tmp;
extern int16_t *src1_ptr_tmp;
extern uint8_t *dst_tmp;
extern uint32_t loop_cnt;
extern uint32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (cnt = (width >> 4); cnt--;) {
        src0_ptr_tmp = src0_ptr;
        src1_ptr_tmp = src1_ptr;
        dst_tmp = dst;
        
        // Unroll and modify memory access to consecutive byte-wise reads with incremental strides
        uint8_t s0[16];
        int16_t s1[16];
        uint8_t d[16];

        // Preload data using consecutive access over width dimension
        for (int i = 0; i < 16; i++) {
            s0[i] = src0_ptr_tmp[i * src_stride];
            s1[i] = src1_ptr_tmp[i * src2_stride];
            d[i] = dst_tmp[i * dst_stride];
        }

        // Perform dummy operations to simulate processing
        for (int i = 0; i < 16; i++) {
            d[i] ^= (uint8_t)(s1[i] & 0xFF);
        }

        // Write back results with consecutive write pattern
        for (int i = 0; i < 16; i++) {
            dst_tmp[i * dst_stride] = d[i];
        }

        src0_ptr_tmp += (7 * src_stride);

        for (loop_cnt = (height >> 1); loop_cnt--;) {
            src0_ptr_tmp += (2 * src_stride);
            src1_ptr_tmp += (2 * src2_stride);
            dst_tmp += (2 * dst_stride);

            // Apply strided gather-like access: jump in larger steps across source arrays
            const int step = 4;
            uint8_t temp_dst[4];
            for (int i = 0; i < 4; i++) {
                int idx = i * step;
                uint8_t val0 = src0_ptr_tmp[idx * src_stride];
                int16_t val1 = src1_ptr_tmp[idx * src2_stride];
                temp_dst[i] = (uint8_t)((val0 + (val1 >> 2)) & 0xFF);
            }

            // Scatter output with non-unit stride
            for (int i = 0; i < 4; i++) {
                int idx = i * step;
                dst_tmp[idx * dst_stride] = temp_dst[i];
            }
        }

        src0_ptr += 16;
        src1_ptr += 16;
        dst += 16;
    }
}
