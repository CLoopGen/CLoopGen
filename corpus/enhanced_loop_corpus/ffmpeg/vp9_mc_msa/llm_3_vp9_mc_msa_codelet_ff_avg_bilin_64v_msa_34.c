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
    // Use strided memory access with a fixed stride over flattened index
    ptrdiff_t total_src_elements = src_stride * height;
    ptrdiff_t total_dst_elements = dst_stride * height;
    int width = 8; // Assume fixed block width based on original pattern

    for (loop_cnt = 0; loop_cnt < (height >> 1); loop_cnt++) {
        ptrdiff_t base_idx0 = loop_cnt * 2 * src_stride;
        ptrdiff_t base_idx1 = base_idx0 + src_stride;
        ptrdiff_t dst_idx0 = loop_cnt * 2 * dst_stride;
        ptrdiff_t dst_idx1 = dst_idx0 + dst_stride;

        for (int w = 0; w < width; w++) {
            if (w < 4) {
                dst[dst_idx0 + w] = src[base_idx0 + w];
                dst[dst_idx1 + w] = src[base_idx1 + w];
            } else {
                dst[dst_idx0 + w] = src[base_idx0 + w];
                dst[dst_idx1 + w] = src[base_idx1 + w];
            }
        }
    }

    // Update global pointers to reflect advancement
    src += (height & ~1) * src_stride;
    dst += (height & ~1) * dst_stride;
}
