#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access using index arithmetic instead of pointer arithmetic
    for (i = 0; i < h; i++) {
        int src_offset = i * srcStride;
        int dst_offset = i * dstStride;
        dst[dst_offset + 0] = cm[(9 * (src[src_offset + 0] + src[src_offset + 1]) - (src[src_offset - 1] + src[src_offset + 2]) + 8) >> 4];
        dst[dst_offset + 1] = cm[(9 * (src[src_offset + 1] + src[src_offset + 2]) - (src[src_offset + 0] + src[src_offset + 3]) + 8) >> 4];
        dst[dst_offset + 2] = cm[(9 * (src[src_offset + 2] + src[src_offset + 3]) - (src[src_offset + 1] + src[src_offset + 4]) + 8) >> 4];
        dst[dst_offset + 3] = cm[(9 * (src[src_offset + 3] + src[src_offset + 4]) - (src[src_offset + 2] + src[src_offset + 5]) + 8) >> 4];
        dst[dst_offset + 4] = cm[(9 * (src[src_offset + 4] + src[src_offset + 5]) - (src[src_offset + 3] + src[src_offset + 6]) + 8) >> 4];
        dst[dst_offset + 5] = cm[(9 * (src[src_offset + 5] + src[src_offset + 6]) - (src[src_offset + 4] + src[src_offset + 7]) + 8) >> 4];
        dst[dst_offset + 6] = cm[(9 * (src[src_offset + 6] + src[src_offset + 7]) - (src[src_offset + 5] + src[src_offset + 8]) + 8) >> 4];
        dst[dst_offset + 7] = cm[(9 * (src[src_offset + 7] + src[src_offset + 8]) - (src[src_offset + 6] + src[src_offset + 9]) + 8) >> 4];
    }
}
