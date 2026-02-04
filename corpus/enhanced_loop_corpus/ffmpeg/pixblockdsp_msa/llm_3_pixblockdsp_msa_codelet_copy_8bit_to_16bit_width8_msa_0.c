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
    // Use indirect access via index array to simulate irregular memory access
    int32_t indices[4] = {0, 1, 2, 3};
    for (cnt = (height >> 2); cnt--;) {
        for (int row = 0; row < 4; ++row) {
            int32_t s_idx = indices[row] * src_stride;
            int32_t d_idx = indices[row] * dst_stride * 2;

            // Strided and scattered read from source, wider stride in destination
            for (int col = 0; col < 8; ++col) {
                dst_ptr[d_idx + col*2] = src[s_idx + col];  // Storing every other byte in dst
            }
        }

        // Advance base pointers by block
        src += (4 * src_stride);
        dst_ptr += (8 * dst_stride); // Increased jump due to expanded storage
    }
}
