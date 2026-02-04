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

        // Change access pattern to indirect via index array for irregular memory traversal
        static const int32_t indices[8] = {0, 2, 4, 6, 1, 3, 5, 7};

        // Use indirect addressing for both read and write operations
        for (int k = 0; k < 8; k++) {
            int32_t idx = indices[k];
            uint8_t val0 = *(src0_ptr_tmp + idx * src_stride);
            int16_t val1 = *(src1_ptr_tmp + idx * src2_stride);
            uint8_t result = (uint8_t)(val0 ^ (val1 & 0xFF));

            *(dst_tmp + idx * dst_stride) = result;
        }

        src0_ptr_tmp += (7 * src_stride);

        for (loop_cnt = (height >> 1); loop_cnt--;) {
            src0_ptr_tmp += (2 * src_stride);
            src1_ptr_tmp += (2 * src2_stride);
            dst_tmp += (2 * dst_stride);

            // Deepen the indirect access with dynamic offset calculation
            for (int k = 0; k < 8; k++) {
                // Simulate variable stride access using quadratic offset
                int32_t offset = (k * k + k) & 7; // bounded non-linear index
                int32_t s0_off = offset * src_stride;
                int32_t s1_off = offset * src2_stride;
                int32_t d_off  = offset * dst_stride;

                uint8_t a = src0_ptr_tmp[s0_off];
                int16_t b = src1_ptr_tmp[s1_off];
                uint8_t res = (uint8_t)((a + (b << 1)) & 0xFF);
                dst_tmp[d_off] = res;
            }

            // Additional dummy structured accesses to maintain complexity
            for (int i = 0; i < 2; i++) {
                __builtin_memcpy(dst_tmp + i * 4 * dst_stride,
                                src0_ptr_tmp + i * 4 * src_stride,
                                sizeof(uint8_t));
            }
        }

        // Advance pointers by vector width in linear space
        src0_ptr += 16;
        src1_ptr += 16;
        dst += 16;
    }
}
