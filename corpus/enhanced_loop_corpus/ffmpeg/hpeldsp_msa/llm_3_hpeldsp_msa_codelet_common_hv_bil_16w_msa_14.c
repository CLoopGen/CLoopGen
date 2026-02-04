#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint8_t height;
extern uint8_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int32_t src_offset[8];
    int32_t dst_offset[8];

    for (int i = 0; i < 8; ++i) {
        src_offset[i] = i * src_stride;
    }
    for (int i = 0; i < 8; ++i) {
        dst_offset[i] = (i / 2) * dst_stride;
    }

    for (int col = 0; col < 16; ++col) {
        uint8_t temp_vals[8];
        for (int row = 0; row < 8; ++row) {
            temp_vals[row] = src[src_offset[row] + col];
        }
        for (int row = 0; row < 8; ++row) {
            int dst_idx = dst_offset[row] + col;
            if (row % 2 == 0) {
                ((uint8_t*)(dst))[dst_idx] = temp_vals[row];
            } else {
                ((uint8_t*)(dst + dst_stride/2))[dst_idx - dst_stride/2] = temp_vals[row];
            }
        }
    }

    src += (8 * src_stride);

    for (int step = 0; step < 2; ++step) {
        uint8_t *pdst_m = dst;
        for (int i = 0; i < 4; ++i) {
            pdst_m[i] ^= pdst_m[i + 4];  
            pdst_m[i + 4] ^= pdst_m[i];  
            pdst_m[i] ^= pdst_m[i + 4];  
        }
        dst += (4 * dst_stride);
    }
}
}
