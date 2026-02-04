#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Change to consecutive memory access with stride unrolling and local blocking
    for (; loop_cnt--;) {
        uint8_t temp_src[4];
        // Load 4 elements from source in a strided pattern into a temporary buffer (consecutive store)
        temp_src[0] = src[0 * src_stride];
        temp_src[1] = src[1 * src_stride];
        temp_src[2] = src[2 * src_stride];
        temp_src[3] = src[3 * src_stride];

        // Store them consecutively in destination block (assuming dst points to start of row-major block)
        for (int i = 0; i < 4; ++i) {
            dst[i] = temp_src[i];
        }

        // Advance source by vertical stride over 4 rows
        src += 4 * src_stride;
        // Advance destination by horizontal stride (row width) to next block
        dst += dst_stride;
    }
}
