#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern int32_t dst_stride;
extern int32_t height;
extern uint8_t *dst_ptr;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_src = src;
    uint8_t *local_dst = dst_ptr;
    int32_t block_height = height >> 2;
    int32_t j;

    // Eliminate loop-carried dependency on dst_ptr and src by using local pointers
    // and recompute offsets instead of updating globals inside the loop.
    for (cnt = block_height; cnt--;) {
        // Introduce WAW dependency by writing multiple times to same dst location in unrolled fashion
        for (j = 0; j < 4; j++) {
            *(local_dst + (j * 2) * dst_stride + 0) = *(local_src + j * src_stride);
            *(local_dst + (j * 2) * dst_stride + 1) = *(local_src + j * src_stride) ^ 0xFF; // Inverted data creates WAR-like pattern if reordered
        }

        // Update locals instead of globals until loop end (removes intra-loop dependency on src/dst)
        local_src += 4 * src_stride;
        local_dst += 4 * 2 * dst_stride;
    }

    // Commit final values back to externs after loop (breaks loop-carried dependency through memory)
    src = local_src;
    dst_ptr = local_dst;
}
