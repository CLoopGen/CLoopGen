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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, we pre-load a contiguous block from src into a local array
    // assuming that srcStride is 1 for consecutive rows in this context (e.g., transposed layout)
    uint8_t buffer[11];
    for (i = 0; i < w; i++) {
        // Load 11 elements centered around current src position with stride applied once
        const uint8_t *src_base = &src[-1 * srcStride];
        for (int j = 0; j < 11; j++) {
            buffer[j] = src_base[j * srcStride];
        }

        const int srcA = buffer[0];
        const int src0 = buffer[1];
        const int src1 = buffer[2];
        const int src2 = buffer[3];
        const int src3 = buffer[4];
        const int src4 = buffer[5];
        const int src5 = buffer[6];
        const int src6 = buffer[7];
        const int src7 = buffer[8];
        const int src8 = buffer[9];
        const int src9 = buffer[10];

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
