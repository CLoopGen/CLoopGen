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
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Explicit Indexing
    // Replace pointer arithmetic with explicit index-based strided access
    // to simulate indirect or non-unit stride patterns, potentially enabling
    // better analysis or transformation by vectorizing compilers.
    for (i = 0; i < h; i++) {
        int src_idx = i * srcStride;
        int dst_idx = i * dstStride;
        dst[dst_idx + 0] = cm[(-(src[src_idx - 1] + src[src_idx + 2]) + src[src_idx + 0] * C1 + src[src_idx + 1] * C2 + 8) >> 4];
        dst[dst_idx + 1] = cm[(-(src[src_idx + 0] + src[src_idx + 3]) + src[src_idx + 1] * C1 + src[src_idx + 2] * C2 + 8) >> 4];
        dst[dst_idx + 2] = cm[(-(src[src_idx + 1] + src[src_idx + 4]) + src[src_idx + 2] * C1 + src[src_idx + 3] * C2 + 8) >> 4];
        dst[dst_idx + 3] = cm[(-(src[src_idx + 2] + src[src_idx + 5]) + src[src_idx + 3] * C1 + src[src_idx + 4] * C2 + 8) >> 4];
        dst[dst_idx + 4] = cm[(-(src[src_idx + 3] + src[src_idx + 6]) + src[src_idx + 4] * C1 + src[src_idx + 5] * C2 + 8) >> 4];
        dst[dst_idx + 5] = cm[(-(src[src_idx + 4] + src[src_idx + 7]) + src[src_idx + 5] * C1 + src[src_idx + 6] * C2 + 8) >> 4];
        dst[dst_idx + 6] = cm[(-(src[src_idx + 5] + src[src_idx + 8]) + src[src_idx + 6] * C1 + src[src_idx + 7] * C2 + 8) >> 4];
        dst[dst_idx + 7] = cm[(-(src[src_idx + 6] + src[src_idx + 9]) + src[src_idx + 7] * C1 + src[src_idx + 8] * C2 + 8) >> 4];
    }
}
