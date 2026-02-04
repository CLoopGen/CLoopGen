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
    // Use consecutive memory layout transformation: transpose 4x4 block
    for (loop_cnt = (height >> 2); loop_cnt--;) {
        uint8_t temp[16]; // Local cache for 4x4 block
        int i;

        // Load 4x4 block with strided access into local array (coalesced)
        for (i = 0; i < 16; ++i) {
            int row = i / 4;
            int col = i % 4;
            temp[i] = src[row * src_stride + col];
        }

        // Store transposed 4x4 block back with strided writes
        for (i = 0; i < 16; ++i) {
            int row = i / 4;
            int col = i % 4;
            dst[col * dst_stride + row] = temp[i];
        }

        src += 4 * src_stride;
        dst += 4 * dst_stride;
    }
}
