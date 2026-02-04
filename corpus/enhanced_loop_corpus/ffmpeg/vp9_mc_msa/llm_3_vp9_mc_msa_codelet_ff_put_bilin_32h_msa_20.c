#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with vertical skipping (every other row with offset)
    ptrdiff_t src_offset = src_stride * 2;
    ptrdiff_t dst_offset = dst_stride * 2;
    uint8_t *local_src = src;
    uint8_t *local_dst = dst;

    for (loop_cnt = height >> 2; loop_cnt--;) {
        // Access non-consecutive source and destination lines
        uint8_t *s0 = local_src;
        uint8_t *s2 = local_src + src_offset;
        uint8_t *d0 = local_dst;
        uint8_t *d2 = local_dst + dst_offset;

        // Simulate block-wise copy with strided source/destination
        for (int col = 0; col < 16; col++) {
            d0[col] = s0[col];
            d2[col] = s2[col];
        }

        local_src += src_stride * 4;
        local_dst += dst_stride * 4;
    }

    // Update original pointers if needed (side-effect preservation)
    src = local_src;
    dst = local_dst;
}
