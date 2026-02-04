#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint8_t *src;
extern ptrdiff_t src_stride;
extern int height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t* local_dst = dst;
    const uint8_t* local_src = src;
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Break loop-carried dependency on dst and src by using locals
        // and unroll with independent writes
        *(uint32_t*)&local_dst[0] = *(const uint32_t*)&local_src[0];
        *(uint32_t*)&local_dst[dst_stride] = *(const uint32_t*)&local_src[src_stride];
        *(uint32_t*)&local_dst[2*dst_stride] = *(const uint32_t*)&local_src[2*src_stride];
        *(uint32_t*)&local_dst[3*dst_stride] = *(const uint32_t*)&local_src[3*src_stride];

        // Update pointers independently after full block write
        local_src += (4 * src_stride);
        local_dst += (4 * dst_stride);
    }
    // Commit final state back to globals (simulated effect; in real usage, may require semantics adjustment)
    dst = local_dst;
    src = local_src;
}
