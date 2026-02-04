#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i += 2) {  // Process two elements per iteration (consecutive access pattern)
        int i1 = i;
        int i2 = i + 1;
        if (i2 >= w) break;

        // Precompute base pointers for spatial locality
        uint8_t *src_m1 = src - srcStride;
        uint8_t *src_0  = src;
        uint8_t *src_p1 = src + srcStride;
        uint8_t *src_p2 = src + 2*srcStride;

        // First pixel
        dst[i1] = (((dst[i1]) + cm[
            (src_m1[i1-1] - 12*src_m1[i1] - 6*src_m1[i1+1] + src_m1[i1+2] +
             -6*src_0[i1-1] + 72*src_0[i1] + 36*src_0[i1+1] - 6*src_0[i1+2] +
             -12*src_p1[i1-1] + 144*src_p1[i1] + 72*src_p1[i1+1] - 12*src_p1[i1+2] +
             src_p2[i1-1] - 12*src_p2[i1] - 6*src_p2[i1+1] + src_p2[i1+2] + 128) >> 8] + 1) >> 1);

        // Second pixel using same kernel with offset
        dst[i2] = (((dst[i2]) + cm[
            (src_m1[i2-1] - 12*src_m1[i2] - 6*src_m1[i2+1] + src_m1[i2+2] +
             -6*src_0[i2-1] + 72*src_0[i2] + 36*src_0[i2+1] - 6*src_0[i2+2] +
             -12*src_p1[i2-1] + 144*src_p1[i2] + 72*src_p1[i2+1] - 12*src_p1[i2+2] +
             src_p2[i2-1] - 12*src_p2[i2] - 6*src_p2[i2+1] + src_p2[i2+2] + 128) >> 8] + 1) >> 1);
    }
    // Handle odd width if needed (tail case)
    if (i < w) {
        uint8_t *src_m1 = src - srcStride;
        uint8_t *src_0  = src;
        uint8_t *src_p1 = src + srcStride;
        uint8_t *src_p2 = src + 2*srcStride;
        dst[i] = (((dst[i]) + cm[
            (src_m1[i-1] - 12*src_m1[i] - 6*src_m1[i+1] + src_m1[i+2] +
             -6*src_0[i-1] + 72*src_0[i] + 36*src_0[i+1] - 6*src_0[i+2] +
             -12*src_p1[i-1] + 144*src_p1[i] + 72*src_p1[i+1] - 12*src_p1[i+2] +
             src_p2[i-1] - 12*src_p2[i] - 6*src_p2[i+1] + src_p2[i+2] + 128) >> 8] + 1) >> 1);
    }
    src += srcStride;
    dst += dstStride;
}
}
