#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Array
    // Use an array of pointers to enable indirect and potentially reordered access
    const uint8_t *src_ptrs[11];
    for (i = 0; i < w; i++) {
        // Build an array of pointers at different strided offsets
        src_ptrs[0] = &src[-1 * srcStride];
        src_ptrs[1] = &src[0 * srcStride];
        src_ptrs[2] = &src[1 * srcStride];
        src_ptrs[3] = &src[2 * srcStride];
        src_ptrs[4] = &src[3 * srcStride];
        src_ptrs[5] = &src[4 * srcStride];
        src_ptrs[6] = &src[5 * srcStride];
        src_ptrs[7] = &src[6 * srcStride];
        src_ptrs[8] = &src[7 * srcStride];
        src_ptrs[9] = &src[8 * srcStride];
        src_ptrs[10] = &src[9 * srcStride];

        // Dereference through pointer array
        const int srcA = *src_ptrs[0];
        const int src0 = *src_ptrs[1];
        const int src1 = *src_ptrs[2];
        const int src2 = *src_ptrs[3];
        const int src3 = *src_ptrs[4];
        const int src4 = *src_ptrs[5];
        const int src5 = *src_ptrs[6];
        const int src6 = *src_ptrs[7];
        const int src7 = *src_ptrs[8];
        const int src8 = *src_ptrs[9];
        const int src9 = *src_ptrs[10];

        dst[0 * dstStride] = cm[(-(srcA + src2) + src0 * C1 + src1 * C2 + 8) >> 4];
        dst[1 * dstStride] = cm[(-(src0 + src3) + src1 * C1 + src2 * C2 + 8) >> 4];
        dst[2 * dstStride] = cm[(-(src1 + src4) + src2 * C1 + src3 * C2 + 8) >> 4];
        dst[3 * dstStride] = cm[(-(src2 + src5) + src3 * C1 + src4 * C2 + 8) >> 4];
        dst[4 * dstStride] = cm[(-(src3 + src6) + src4 * C1 + src5 * C2 + 8) >> 4];
        dst[5 * dstStride] = cm[(-(src4 + src7) + src5 * C1 + src6 * C2 + 8) >> 4];
        dst[6 * dstStride] = cm[(-(src5 + src8) + src6 * C1 + src7 * C2 + 8) >> 4];
        dst[7 * dstStride] = cm[(-(src6 + src9) + src7 * C1 + src8 * C2 + 8) >> 4];

        dst++;
        src++;
    }
}
