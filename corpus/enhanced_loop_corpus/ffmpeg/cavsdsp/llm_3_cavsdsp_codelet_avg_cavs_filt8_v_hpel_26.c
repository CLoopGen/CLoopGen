#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const uint8_t **src_ptr = (const uint8_t **)malloc(11 * sizeof(uint8_t *));
if (!src_ptr) return;
for (int idx = -2; idx <= 8; idx++) {
    src_ptr[idx + 2] = &src[idx * srcStride];
}

for (i = 0; i < w; i++) {
    const int srcB = *src_ptr[0];  
    const int srcA = *src_ptr[1];  
    const int src0 = *src_ptr[2];  
    const int src1 = *src_ptr[3];  
    const int src2 = *src_ptr[4];  
    const int src3 = *src_ptr[5];  
    const int src4 = *src_ptr[6];  
    const int src5 = *src_ptr[7];  
    const int src6 = *src_ptr[8];  
    const int src7 = *src_ptr[9];  
    const int src8 = *src_ptr[10]; 
    const int src9 = *(src + (9 + i) * srcStride);
    const int src10 = *(src + (10 + i) * srcStride);

    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((0*srcB -1*srcA +5*src0 +5*src1 -1*src2 +0*src3) + 4) >> 3] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((0*srcA -1*src0 +5*src1 +5*src2 -1*src3 +0*src4) + 4) >> 3] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((0*src0 -1*src1 +5*src2 +5*src3 -1*src4 +0*src5) + 4) >> 3] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[((0*src1 -1*src2 +5*src3 +5*src4 -1*src5 +0*src6) + 4) >> 3] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[((0*src2 -1*src3 +5*src4 +5*src5 -1*src6 +0*src7) + 4) >> 3] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[((0*src3 -1*src4 +5*src5 +5*src6 -1*src7 +0*src8) + 4) >> 3] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[((0*src4 -1*src5 +5*src6 +5*src7 -1*src8 +0*src9) + 4) >> 3] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[((0*src5 -1*src6 +5*src7 +5*src8 -1*src9 +0*src10) + 4) >> 3] + 1) >> 1;

    for (int j = 0; j < 11; j++) {
        if (j < 10) src_ptr[j]++;
    }
    dst++;
    src++;
}
free(src_ptr);
}
