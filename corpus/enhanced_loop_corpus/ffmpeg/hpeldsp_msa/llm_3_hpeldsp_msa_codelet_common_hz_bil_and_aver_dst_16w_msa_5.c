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
    // Change to consecutive memory access by transposing block-wise load/store
    // Process 8x8 block from src and transpose into 8x8 in dst as 8 rows of 8 bytes
    for (int row = 0; row < 8; ++row) {
        uint8_t temp[8];
        uint8_t *src_row = src + row * src_stride;
        for (int col = 0; col < 8; ++col) {
            temp[col] = src_row[col];  // Load full row consecutively
        }
        // Store transposed: each element goes to a different destination row
        for (int col = 0; col < 8; ++col) {
            dst[col * dst_stride + row] = temp[col];
        }
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
