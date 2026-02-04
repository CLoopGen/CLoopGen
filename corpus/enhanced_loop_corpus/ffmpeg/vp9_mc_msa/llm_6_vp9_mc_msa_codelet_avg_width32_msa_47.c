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
    uint8_t *src_local = src;
    uint8_t *dst_local = dst;
    uint8_t *dst_dup_local = dst_dup;
    int32_t stride4_src = 4 * src_stride;
    int32_t stride4_dst = 4 * dst_stride;

    for (cnt = (height / 4); cnt--;) {
        // Introduce local computation with carried dependency via accumulator
        uint32_t acc = 0;
        acc += src_local[0];
        acc += src_local[stride4_src / 4];
        acc += src_local[2 * stride4_src / 4];
        acc += src_local[3 * stride4_src / 4];

        // Use accumulated value to modify dst_dup write (introducing WAW and RAW)
        dst_dup_local[0] = (uint8_t)(acc >> 8);
        dst_dup_local[stride4_dst / 4] = (uint8_t)(acc >> 4);
        dst_dup_local[2 * stride4_dst / 4] = (uint8_t)(acc);
        dst_dup_local[3 * stride4_dst / 4] = (uint8_t)(acc << 2);

        // RAW: dst depends on prior dst_dup writes in same iteration
        dst_local[0] = dst_dup_local[0] + 1;
        dst_local[stride4_dst / 4] = dst_dup_local[stride4_dst / 4] + 1;
        dst_local[2 * stride4_dst / 4] = dst_dup_local[2 * stride4_dst / 4] + 1;
        dst_local[3 * stride4_dst / 4] = dst_dup_local[3 * stride4_dst / 4] + 1;

        // Update pointers after use — introduces loop-carried pointer dependency
        src_local += stride4_src;
        dst_local += stride4_dst;
        dst_dup_local += stride4_dst;
    }

    // Final update to globals to reflect changes
    src = src_local;
    dst = dst_local;
    dst_dup = dst_dup_local;
}
