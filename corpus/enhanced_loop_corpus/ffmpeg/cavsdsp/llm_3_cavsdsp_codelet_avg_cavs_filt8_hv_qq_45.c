#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    const int16_t *tmp_base = tmp;
    uint8_t *d = dst;

    // Unroll and reorganize memory access to use consecutive loads with local accumulation
    int tmp_vals[13];
    for (int j = -2; j <= 10; j++) {
        tmp_vals[j + 2] = tmp_base[j * 8];
    }

    const int tmpB = tmp_vals[0];
    const int tmpA = tmp_vals[1];
    const int tmp0 = tmp_vals[2];
    const int tmp1 = tmp_vals[3];
    const int tmp2 = tmp_vals[4];
    const int tmp3 = tmp_vals[5];
    const int tmp4 = tmp_vals[6];
    const int tmp5 = tmp_vals[7];
    const int tmp6 = tmp_vals[8];
    const int tmp7 = tmp_vals[9];
    const int tmp8 = tmp_vals[10];
    const int tmp9 = tmp_vals[11];
    const int tmp10 = tmp_vals[12];

    // Use a local array to batch updates before writing back
    uint8_t new_dst[8];
    new_dst[0] = cm[((0 * tmpB + -7 * tmpA + 42 * tmp0 + 96 * tmp1 + -2 * tmp2 + -1 * tmp3) + 512) >> 10];
    new_dst[1] = cm[((0 * tmpA + -7 * tmp0 + 42 * tmp1 + 96 * tmp2 + -2 * tmp3 + -1 * tmp4) + 512) >> 10];
    new_dst[2] = cm[((0 * tmp0 + -7 * tmp1 + 42 * tmp2 + 96 * tmp3 + -2 * tmp4 + -1 * tmp5) + 512) >> 10];
    new_dst[3] = cm[((0 * tmp1 + -7 * tmp2 + 42 * tmp3 + 96 * tmp4 + -2 * tmp5 + -1 * tmp6) + 512) >> 10];
    new_dst[4] = cm[((0 * tmp2 + -7 * tmp3 + 42 * tmp4 + 96 * tmp5 + -2 * tmp6 + -1 * tmp7) + 512) >> 10];
    new_dst[5] = cm[((0 * tmp3 + -7 * tmp4 + 42 * tmp5 + 96 * tmp6 + -2 * tmp7 + -1 * tmp8) + 512) >> 10];
    new_dst[6] = cm[((0 * tmp4 + -7 * tmp5 + 42 * tmp6 + 96 * tmp7 + -2 * tmp8 + -1 * tmp9) + 512) >> 10];
    new_dst[7] = cm[((0 * tmp5 + -7 * tmp6 + 42 * tmp7 + 96 * tmp8 + -2 * tmp9 + -1 * tmp10) + 512) >> 10];

    // Apply update with strided write using dstStride
    for (int k = 0; k < 8; k++) {
        d[k * dstStride] = ((d[k * dstStride]) + new_dst[k] + 1) >> 1;
    }

    dst++;
    tmp++;
}
}
