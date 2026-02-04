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
    // Unroll the inner computation to increase computational intensity
    const int offsets[] = { -2*8, -1*8, 0*8, 1*8, 2*8, 3*8, 4*8, 5*8, 6*8, 7*8, 8*8, 9*8, 10*8 };
    const int coeffs0[] = { -1, -2, 96, 42, -7, 0 }; // for row 0
    const int coeffs1[] = { 0, -1, -2, 96, 42, -7 }; // for row 1
    const int coeffs2[] = { 0, 0, -1, -2, 96, 42 }; // simplified pattern

    const int t0 = tmp[offsets[0]], t1 = tmp[offsets[1]], t2 = tmp[offsets[2]], t3 = tmp[offsets[3]];
    const int t4 = tmp[offsets[4]], t5 = tmp[offsets[5]], t6 = tmp[offsets[6]], t7 = tmp[offsets[7]];
    const int t8 = tmp[offsets[8]], t9 = tmp[offsets[9]], t10 = tmp[offsets[10]];

    // Compute multiple outputs using reused terms and expanded operations
    int sum0 = coeffs0[0]*t0 + coeffs0[1]*t1 + coeffs0[2]*t2 + coeffs0[3]*t3 + coeffs0[4]*t4 + coeffs0[5]*t5;
    int sum1 = coeffs1[0]*t1 + coeffs1[1]*t2 + coeffs1[2]*t3 + coeffs1[3]*t4 + coeffs1[4]*t5 + coeffs1[5]*t6;
    int sum2 = coeffs2[0]*t2 + coeffs2[1]*t3 + coeffs2[2]*t4 + coeffs2[3]*t5 + coeffs2[4]*t6 + coeffs2[5]*t7;

    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(sum0 + 512) >> 10] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(sum1 + 512) >> 10] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(sum2 + 512) >> 10] + 1) >> 1;

    // Skip every other column to reduce memory writes but keep high compute
    dst++;
    tmp++;
    i++; // Compensate for increased work per iteration
    if (i >= w) break;
}
}
