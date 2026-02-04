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
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        // Interleaved strided access with reversed processing order
        for (int offset = 0; offset < 4; ++offset) {
            int idx = 3 - offset; // Reverse the row order within each 4-row block
            uint8_t *s = src + idx * src_stride;
            uint8_t *d = dst + idx * dst_stride;

            // Process multiple elements with unit stride at once
            for (int elem = 0; elem < 4; ++elem) {
                d[elem] = s[elem];
            }
        }

        src += (4 * src_stride);
        dst += (4 * dst_stride);
    }
}
