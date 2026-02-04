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
    const int tmpB = tmp[idx - 2 * 8];
    const int tmpA = tmp[idx - 1 * 8];
    const int tmp0 = tmp[idx + 0 * 8];
    const int tmp1 = tmp[idx + 1 * 8];
    const int tmp2 = tmp[idx + 2 * 8];
    const int tmp3 = tmp[idx + 3 * 8];
    const int tmp4 = tmp[idx + 4 * 8];
    const int tmp5 = tmp[idx + 5 * 8];
    const int tmp6 = tmp[idx + 6 * 8];
    const int tmp7 = tmp[idx + 7 * 8];
    const int tmp8 = tmp[idx + 8 * 8];
    const int tmp9 = tmp[idx + 9 * 8];
    const int tmp10 = tmp[idx + 10 * 8];
    const ptrdiff_t s2off = i * srcStride;
    const ptrdiff_t dstoff = i * dstStride;
    ((uint8_t*)dst)[dstoff + 0] = cm[((-1 * tmpB + -2 * tmpA + 96 * tmp0 + 42 * tmp1 + -7 * tmp2 + 0 * tmp3 + 64 * ((uint8_t*)src2)[s2off + 0]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 1] = cm[((-1 * tmpA + -2 * tmp0 + 96 * tmp1 + 42 * tmp2 + -7 * tmp3 + 0 * tmp4 + 64 * ((uint8_t*)src2)[s2off + 1]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 2] = cm[((-1 * tmp0 + -2 * tmp1 + 96 * tmp2 + 42 * tmp3 + -7 * tmp4 + 0 * tmp5 + 64 * ((uint8_t*)src2)[s2off + 2]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 3] = cm[((-1 * tmp1 + -2 * tmp2 + 96 * tmp3 + 42 * tmp4 + -7 * tmp5 + 0 * tmp6 + 64 * ((uint8_t*)src2)[s2off + 3]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 4] = cm[((-1 * tmp2 + -2 * tmp3 + 96 * tmp4 + 42 * tmp5 + -7 * tmp6 + 0 * tmp7 + 64 * ((uint8_t*)src2)[s2off + 4]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 5] = cm[((-1 * tmp3 + -2 * tmp4 + 96 * tmp5 + 42 * tmp6 + -7 * tmp7 + 0 * tmp8 + 64 * ((uint8_t*)src2)[s2off + 5]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 6] = cm[((-1 * tmp4 + -2 * tmp5 + 96 * tmp6 + 42 * tmp7 + -7 * tmp8 + 0 * tmp9 + 64 * ((uint8_t*)src2)[s2off + 6]) + 512) >> 10];
    ((uint8_t*)dst)[dstoff + 7] = cm[((-1 * tmp5 + -2 * tmp6 + 96 * tmp7 + 42 * tmp8 + -7 * tmp9 + 0 * tmp10 + 64 * ((uint8_t*)src2)[s2off + 7]) + 512) >> 10];
}
}
