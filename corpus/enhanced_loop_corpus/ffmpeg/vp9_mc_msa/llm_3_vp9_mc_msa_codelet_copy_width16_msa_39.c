#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access with array indexing instead of pointer arithmetic
    int32_t i;
    for (i = 0; i < height; i += 4) {
        int32_t src_idx1 = i * src_stride;
        int32_t src_idx2 = (i + 1) * src_stride;
        int32_t src_idx3 = (i + 2) * src_stride;
        int32_t src_idx4 = (i + 3) * src_stride;

        int32_t dst_idx1 = i * dst_stride;
        int32_t dst_idx2 = (i + 1) * dst_stride;
        int32_t dst_idx3 = (i + 2) * dst_stride;
        int32_t dst_idx4 = (i + 3) * dst_stride;

        // Access elements using computed indices (consecutive logical access)
        dst[dst_idx1] = src[src_idx1];
        dst[dst_idx2] = src[src_idx2];
        dst[dst_idx3] = src[src_idx3];
        dst[dst_idx4] = src[src_idx4];
    }
}
