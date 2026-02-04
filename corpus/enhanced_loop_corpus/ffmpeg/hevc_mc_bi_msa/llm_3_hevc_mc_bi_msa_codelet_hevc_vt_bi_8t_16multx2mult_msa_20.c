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



void loop(){
for (cnt = (width >> 4); cnt--;) {
    src0_ptr_tmp = src0_ptr;
    src1_ptr_tmp = src1_ptr;
    dst_tmp = dst;
    int access_pattern[8] = {0, 2, 4, 6, 1, 3, 5, 7};
    for (int k = 0; k < 8; k++) {
        int row = access_pattern[k];
        for (int col = 0; col < 2; col++) {
            uint8_t s0_val = src0_ptr_tmp[row * src_stride + col];
            int16_t s1_val = src1_ptr_tmp[row * src2_stride + col];
            dst_tmp[row * dst_stride + col] = (uint8_t)((s0_val + s1_val) & 0xFF);
        }
    }
    src0_ptr_tmp += (7 * src_stride);
    int rev_pattern[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (int k = 0; k < 8; k++) {
        int row = rev_pattern[k];
        for (int col = 0; col < 2; col++) {
            uint8_t s0_val = src0_ptr_tmp[row * src_stride + col];
            int16_t s1_val = src1_ptr_tmp[row * src2_stride + col];
            dst_tmp[row * dst_stride + col + 1] = (uint8_t)((s0_val + s1_val) & 0xFF);
        }
    }
    for (int k = 0; k < 4; k++) {
        int ind_map = (k * 3) & 7;
        uint8_t s0_val = src0_ptr_tmp[ind_map * src_stride + (k & 1)];
        int16_t s1_val = src1_ptr_tmp[ind_map * src2_stride + (k & 1)];
        dst_tmp[ind_map * dst_stride + (k & 1)] ^= (uint8_t)(s0_val ^ s1_val);
    }
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        src0_ptr_tmp += (2 * src_stride);
        src1_ptr_tmp += (2 * src2_stride);
        for (int vec = 0; vec < 16; vec += 4) {
            int offsets[4] = {0, 1, src_stride, src_stride + 1};
            for (int v = 0; v < 4; v++) {
                size_t s0_idx = (size_t)(src0_ptr_tmp + offsets[v]);
                size_t s1_idx = (size_t)(src1_ptr_tmp + offsets[v]);
                uint8_t val = (uint8_t)((*(uint8_t*)s0_idx + *(int16_t*)s1_idx) & 0xFF);
                *(dst_tmp + offsets[v]) = val;
            }
            dst_tmp += 2;
        }
        dst_tmp += (2 * dst_stride) - 32;
    }
    src0_ptr += 16;
    src1_ptr += 16;
    dst += 16;
}
}
