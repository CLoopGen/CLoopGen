#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int srcHeight;
extern int srcStride;
extern int dstStride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < srcHeight; y++) {
    const int mmxSize = 1;
    int offset_src = y * srcStride;
    int offset_dst = (y - 1) * dstStride * 2;

    dst[offset_dst] = (src[offset_src] * 3 + src[offset_src + srcStride]) >> 2;
    dst[offset_dst + dstStride] = (src[offset_src] + 3 * src[offset_src + srcStride]) >> 2;

    for (x = mmxSize - 1; x < srcWidth - 1; x++) {
        int src_idx = offset_src + x;
        int dst_idx = offset_dst + 2 * x;

        dst[dst_idx + 1] = (src[src_idx] * 3 + src[src_idx + srcStride + 1]) >> 2;
        dst[dst_idx + dstStride + 2] = (src[src_idx] + 3 * src[src_idx + srcStride + 1]) >> 2;
        dst[dst_idx + dstStride + 1] = (src[src_idx + 1] + 3 * src[src_idx + srcStride]) >> 2;
        dst[dst_idx + 2] = (src[src_idx + 1] * 3 + src[src_idx + srcStride]) >> 2;
    }

    int last = srcWidth - 1;
    dst[offset_dst + srcWidth * 2 - 1] = (src[offset_src + last] * 3 + src[offset_src + last + srcStride]) >> 2;
    dst[offset_dst + srcWidth * 2 - 1 + dstStride] = (src[offset_src + last] + 3 * src[offset_src + last + srcStride]) >> 2;
}
}
