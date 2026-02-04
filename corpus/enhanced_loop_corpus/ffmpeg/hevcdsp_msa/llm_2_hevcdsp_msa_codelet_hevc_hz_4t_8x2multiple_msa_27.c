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
for (loop_cnt = (height >> 1); loop_cnt--;) {
    uint8_t *src_ptr1 = src;
    uint8_t *src_ptr2 = src + src_stride;
    int16_t *dst_ptr1 = dst;
    int16_t *dst_ptr2 = dst + dst_stride;

    // Simulate processing with consecutive memory access pattern
    for (int i = 0; i < 4; ++i) {
        dst_ptr1[i] = (int16_t)(src_ptr1[i]);
        dst_ptr2[i] = (int16_t)(src_ptr2[i]);
    }

    src += (2 * src_stride);
    dst += (2 * dst_stride);
}
}
