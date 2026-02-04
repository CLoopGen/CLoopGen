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
    int32_t local_offset = 0;
    for (loop_cnt = height; loop_cnt--;) {
        int32_t idx = local_offset + loop_cnt; // Eliminate loop-carried dependency
        uint8_t val = src[idx];               // Introduce independent indexing
        dst[loop_cnt * dst_stride] = (int16_t)(val * 2); // No dependency on previous iterations
        // All operations are independent — no RAW, WAR, or WAW across iterations
    }
    // Final update of pointers to maintain observable behavior consistency
    src += src_stride * height;
    dst += dst_stride * height;
}
