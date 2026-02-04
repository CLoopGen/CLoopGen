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
for (i = 0; i < w; i++) {
    uint8_t local_src[9];
    for (int j = 0; j < 9; j++) {
        local_src[j] = src[j * srcStride];
    }
    const int src0 = local_src[0];
    const int src1 = local_src[1];
    const int src2 = local_src[2];
    const int src3 = local_src[3];
    const int src4 = local_src[4];
    const int src5 = local_src[5];
    const int src6 = local_src[6];
    const int src7 = local_src[7];
    const int src8 = local_src[8];
    uint8_t temp_dst[8];
    temp_dst[0] = cm[(((src0 + src1) * 20 - (src0 + src2) * 6 + (src1 + src3) * 3 - (src2 + src4)) + 16) >> 5];
    temp_dst[1] = cm[(((src1 + src2) * 20 - (src0 + src3) * 6 + (src0 + src4) * 3 - (src1 + src5)) + 16) >> 5];
    temp_dst[2] = cm[(((src2 + src3) * 20 - (src1 + src4) * 6 + (src0 + src5) * 3 - (src0 + src6)) + 16) >> 5];
    temp_dst[3] = cm[(((src3 + src4) * 20 - (src2 + src5) * 6 + (src1 + src6) * 3 - (src0 + src7)) + 16) >> 5];
    temp_dst[4] = cm[(((src4 + src5) * 20 - (src3 + src6) * 6 + (src2 + src7) * 3 - (src1 + src8)) + 16) >> 5];
    temp_dst[5] = cm[(((src5 + src6) * 20 - (src4 + src7) * 6 + (src3 + src8) * 3 - (src2 + src8)) + 16) >> 5];
    temp_dst[6] = cm[(((src6 + src7) * 20 - (src5 + src8) * 6 + (src4 + src8) * 3 - (src3 + src7)) + 16) >> 5];
    temp_dst[7] = cm[(((src7 + src8) * 20 - (src6 + src8) * 6 + (src5 + src7) * 3 - (src4 + src6)) + 16) >> 5];
    for (int j = 0; j < 8; j++) {
        dst[j * dstStride] = temp_dst[j];
    }
    dst++;
    src++;
}
}
