#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src1 = src;
    uint8_t *src2 = src + src_stride;
    uint8_t *dst1 = dst;
    uint8_t *dst2 = dst + dst_stride;
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Modify memory access to use consecutive loads from two source pointers
        // Simulate a deinterleaved or dual-stream load pattern
        __builtin_memcpy(dst1, src1, sizeof(uint8_t));
        __builtin_memcpy(dst2, src2, sizeof(uint8_t));

        src1 += (src_stride << 1);
        src2 += (src_stride << 1);
        dst1 += (dst_stride << 1);
        dst2 += (dst_stride << 1);
    }
    // Update original pointers if needed (side-effect model)
    src = src2;
    dst = dst2;
}
