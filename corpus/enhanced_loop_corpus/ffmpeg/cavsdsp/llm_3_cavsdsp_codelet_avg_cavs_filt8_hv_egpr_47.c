#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int idx = i * 8;
    const int tmpB = tmp[idx - 16];
    const int tmpA = tmp[idx - 8];
    const int tmp0 = tmp[idx + 0];
    const int tmp1 = tmp[idx + 8];
    const int tmp2 = tmp[idx + 16];
    const int tmp3 = tmp[idx + 24];
    const int tmp4 = tmp[idx + 32];
    const int tmp5 = tmp[idx + 40];
    const int tmp6 = tmp[idx + 48];
    const int tmp7 = tmp[idx + 56];
    const int tmp8 = tmp[idx + 64];
    const int tmp9 = tmp[idx + 72];
    const int tmp10 = tmp[idx + 80];

    ptrdiff_t d_stride = dstStride;
    ptrdiff_t s_stride = srcStride;

    uint8_t val0 = cm[( ( -1*tmpA + 5*tmp0 + 5*tmp1 -1*tmp2 + 64*src2[i*s_stride] ) + 64 ) >> 7];
    uint8_t val1 = cm[( ( -1*tmp0 + 5*tmp1 + 5*tmp2 -1*tmp3 + 64*src2[i*s_stride + s_stride] ) + 64 ) >> 7];
    uint8_t val2 = cm[( ( -1*tmp1 + 5*tmp2 + 5*tmp3 -1*tmp4 + 64*src2[i*s_stride + 2*s_stride] ) + 64 ) >> 7];
    uint8_t val3 = cm[( ( -1*tmp2 + 5*tmp3 + 5*tmp4 -1*tmp5 + 64*src2[i*s_stride + 3*s_stride] ) + 64 ) >> 7];
    uint8_t val4 = cm[( ( -1*tmp3 + 5*tmp4 + 5*tmp5 -1*tmp6 + 64*src2[i*s_stride + 4*s_stride] ) + 64 ) >> 7];
    uint8_t val5 = cm[( ( -1*tmp4 + 5*tmp5 + 5*tmp6 -1*tmp7 + 64*src2[i*s_stride + 5*s_stride] ) + 64 ) >> 7];
    uint8_t val6 = cm[( ( -1*tmp5 + 5*tmp6 + 5*tmp7 -1*tmp8 + 64*src2[i*s_stride + 6*s_stride] ) + 64 ) >> 7];
    uint8_t val7 = cm[( ( -1*tmp6 + 5*tmp7 + 5*tmp8 -1*tmp9 + 64*src2[i*s_stride + 7*s_stride] ) + 64 ) >> 7];

    dst[i*d_stride + 0*d_stride] = ((dst[i*d_stride + 0*d_stride]) + val0 + 1) >> 1;
    dst[i*d_stride + 1*d_stride] = ((dst[i*d_stride + 1*d_stride]) + val1 + 1) >> 1;
    dst[i*d_stride + 2*d_stride] = ((dst[i*d_stride + 2*d_stride]) + val2 + 1) >> 1;
    dst[i*d_stride + 3*d_stride] = ((dst[i*d_stride + 3*d_stride]) + val3 + 1) >> 1;
    dst[i*d_stride + 4*d_stride] = ((dst[i*d_stride + 4*d_stride]) + val4 + 1) >> 1;
    dst[i*d_stride + 5*d_stride] = ((dst[i*d_stride + 5*d_stride]) + val5 + 1) >> 1;
    dst[i*d_stride + 6*d_stride] = ((dst[i*d_stride + 6*d_stride]) + val6 + 1) >> 1;
    dst[i*d_stride + 7*d_stride] = ((dst[i*d_stride + 7*d_stride]) + val7 + 1) >> 1;
}
}
