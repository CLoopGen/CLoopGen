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
    // Use indirect access via index array to simulate irregular memory access pattern
    int indices[4] = {0, 1, 2, 3};
    ptrdiff_t offset;

    for (loop_cnt = (height >> 2); loop_cnt--;) {
        for (int i = 0; i < 4; ++i) {
            offset = indices[i] * src_stride;
            dst[i * dst_stride + 0] = src[offset + 0];
            dst[i * dst_stride + 1] = src[offset + 1];
            dst[i * dst_stride + 2] = src[offset + 2];
            dst[i * dst_stride + 3] = src[offset + 3];
        }

        // Update pointers with fixed stride jump
        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
