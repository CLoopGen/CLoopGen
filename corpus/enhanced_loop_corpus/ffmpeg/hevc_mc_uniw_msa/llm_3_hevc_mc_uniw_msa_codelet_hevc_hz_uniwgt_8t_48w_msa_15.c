#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect access via index array to simulate irregular memory access
static const uint32_t indices[16] = {
    0, 2, 4, 6, 8, 10, 12, 14,
    16, 18, 20, 22, 24, 26, 28, 30
};

for (loop_cnt = 64; loop_cnt--;) {
    uint8_t acc = 0;
    
    // Indirect and strided read from src using index lookup
    for (int j = 0; j < 16; ++j) {
        uint32_t idx = indices[j];
        acc ^= src[idx * (src_stride / 8 + 1)];  // Stride-scaled indirect access
    }
    
    // Write result to multiple scattered locations in dst
    for (int j = 0; j < 8; ++j) {
        uint32_t write_idx = indices[j] * (dst_stride / 8 + 1);
        dst[write_idx] = acc + j;
    }
    
    // Advance pointers by their strides
    src += src_stride;
    dst += dst_stride;
}
}
