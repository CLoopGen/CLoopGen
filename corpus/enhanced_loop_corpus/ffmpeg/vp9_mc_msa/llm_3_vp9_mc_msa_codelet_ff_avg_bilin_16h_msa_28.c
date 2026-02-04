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
    // Use consecutive memory access with linearized indexing
    // Assume row-major layout: flatten 2D access into 1D with precomputed offsets
    ptrdiff_t src_offset = 0;
    ptrdiff_t dst_offset = 0;
    ptrdiff_t src_jump = 4 * src_stride;
    ptrdiff_t dst_jump = 4 * dst_stride;

    for (loop_cnt = (height >> 2) - 1; loop_cnt--;) {
        // Access four consecutive rows in a strided pattern, but write as block
        for (int col = 0; col < 4; ++col) {
            dst[dst_offset + col * dst_stride + 0] = src[src_offset + col * src_stride + 0];
            dst[dst_offset + col * dst_stride + 1] = src[src_offset + col * src_stride + 1];
            dst[dst_offset + col * dst_stride + 2] = src[src_offset + col * src_stride + 2];
            dst[dst_offset + col * dst_stride + 3] = src[src_offset + col * src_stride + 3];
        }

        src_offset += src_jump;
        dst_offset += dst_jump;
    }
}
