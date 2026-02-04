#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (loop_cnt = (height >> 3); loop_cnt--;) {
    int32_t i, j;
    uint8_t **src_ptrs = (uint8_t**)alloca(8 * sizeof(uint8_t*));
    int16_t **dst_ptrs = (int16_t**)alloca(8 * sizeof(int16_t*));

    for (i = 0; i < 8; ++i) {
        src_ptrs[i] = src + i * src_stride;
        dst_ptrs[i] = dst + i * dst_stride;
    }

    for (j = 0; j < 8; ++j) {
        for (i = 0; i < 8; ++i) {
            dst_ptrs[i][j] = (int16_t)src_ptrs[i][j];
        }
    }

    src += (8 * src_stride);
    dst += (8 * dst_stride);
}
}
