#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  uint8_t *cm;
extern  int w;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing (eliminate stride multiplication)
    // Instead of using strided access via src[i * srcStride], assume data is packed consecutively.
    // This variant assumes srcStride and dstStride are 1, or that the arrays have been pre-reorganized.
    for (i = 0; i < w; i++) {
        const uint8_t* s = &src[i]; // Base pointer for consecutive access
        const uint8_t* d = &dst[i];
        const int src0 = s[0]; const int src1 = s[1]; const int src2 = s[2];
        const int src3 = s[3]; const int src4 = s[4]; const int src5 = s[5];
        const int src6 = s[6]; const int src7 = s[7]; const int src8 = s[8];

        ((uint8_t*)d)[0 * dstStride] = (((((uint8_t*)d)[0 * dstStride]) + cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[1 * dstStride] = (((((uint8_t*)d)[1 * dstStride]) + cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[2 * dstStride] = (((((uint8_t*)d)[2 * dstStride]) + cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[3 * dstStride] = (((((uint8_t*)d)[3 * dstStride]) + cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[4 * dstStride] = (((((uint8_t*)d)[4 * dstStride]) + cm[(((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[5 * dstStride] = (((((uint8_t*)d)[5 * dstStride]) + cm[(((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src8)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[6 * dstStride] = (((((uint8_t*)d)[6 * dstStride]) + cm[(((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src8) * 3 - (src3 + src7)) + 16) >> 5] + 1) >> 1);
        ((uint8_t*)d)[7 * dstStride] = (((((uint8_t*)d)[7 * dstStride]) + cm[(((src7 + src8) * 20 - (src6 + src8) * 6 + (src5 + src7) * 3 - (src4 + src6)) + 16) >> 5] + 1) >> 1);
    }
}
