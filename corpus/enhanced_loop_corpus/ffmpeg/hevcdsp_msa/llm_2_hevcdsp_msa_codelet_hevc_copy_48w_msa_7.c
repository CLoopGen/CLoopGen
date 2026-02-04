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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Variant 1: Consecutive memory access with prefetching simulation and reordered operations
        // Access src in consecutive blocks of 4 rows, then process all at once
        uint8_t *src0 = src;
        uint8_t *src1 = src + src_stride;
        uint8_t *src2 = src + 2 * src_stride;
        uint8_t *src3 = src + 3 * src_stride;

        // Simulate vectorized load by grouping accesses
        __builtin_prefetch(src0);
        __builtin_prefetch(src1);
        __builtin_prefetch(src2);
        __builtin_prefetch(src3);

        // Process four source rows (dummy operations to represent computation)
        int16_t *dst0 = dst;
        int16_t *dst1 = dst + dst_stride;
        int16_t *dst2 = dst + 2 * dst_stride;
        int16_t *dst3 = dst + 3 * dst_stride;

        // Dummy arithmetic to simulate useful work
        dst0[0] = (int16_t)(src0[0]) << 1;
        dst1[0] = (int16_t)(src1[0]) << 1;
        dst2[0] = (int16_t)(src2[0]) << 1;
        dst3[0] = (int16_t)(src3[0]) << 1;

        // Advance pointers by full block
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
