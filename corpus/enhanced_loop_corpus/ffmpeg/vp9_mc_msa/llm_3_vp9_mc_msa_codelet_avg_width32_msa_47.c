#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (cnt = (height / 4); cnt--;) {
    // Use indirect access via pointer array to simulate irregular memory access pattern
    uint8_t **src_ptrs = (uint8_t**)alloca(4 * sizeof(uint8_t*));
    uint8_t **dst_ptrs = (uint8_t**)alloca(4 * sizeof(uint8_t*));
    uint8_t **dup_ptrs = (uint8_t**)alloca(4 * sizeof(uint8_t*));

    src_ptrs[0] = src;
    src_ptrs[1] = src + src_stride;
    src_ptrs[2] = src + 2 * src_stride;
    src_ptrs[3] = src + 3 * src_stride;

    dst_ptrs[0] = dst;
    dst_ptrs[1] = dst + dst_stride;
    dst_ptrs[2] = dst + 2 * dst_stride;
    dst_ptrs[3] = dst + 3 * dst_stride;

    dup_ptrs[0] = dst_dup;
    dup_ptrs[1] = dst_dup + dst_stride;
    dup_ptrs[2] = dst_dup + 2 * dst_stride;
    dup_ptrs[3] = dst_dup + 3 * dst_stride;

    // Strided write using indirect addressing with fixed offset
    const int block_size = 8;
    for (int o = 0; o < block_size; o += 2) {
        for (int idx = 0; idx < 4; idx++) {
            dst_ptrs[idx][o + 0] = src_ptrs[idx][o + 0];
            dst_ptrs[idx][o + 1] = src_ptrs[idx][o + 1];
            dup_ptrs[idx][o + 0] = src_ptrs[idx][o + 0];
            dup_ptrs[idx][o + 1] = src_ptrs[idx][o + 1];
        }
    }

    src += 4 * src_stride;
    dst += 4 * dst_stride;
    dst_dup += 4 * dst_stride;
}
}
