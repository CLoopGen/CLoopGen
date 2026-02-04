#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t src_stride;
extern int32_t dst_stride;
extern uint32_t loop_cnt;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count and minimal operations to decrease computational intensity
    for (loop_cnt = 2; loop_cnt--;) {
        // Only update pointers once per iteration with no nested logic
        src_tmp += src_stride;
        dst_tmp += dst_stride;

        // Lightweight operation: single memory touchpoint
        dst_tmp[0] = (int16_t)src_tmp[0];
    }

    // Final adjustment to maintain original total stride effect approximately
    src_tmp += 6 * src_stride;
    dst_tmp += 6 * dst_stride;
}
