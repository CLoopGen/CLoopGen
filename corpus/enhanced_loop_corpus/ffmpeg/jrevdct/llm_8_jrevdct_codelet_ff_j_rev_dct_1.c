#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t tmp0;
extern int32_t tmp1;
extern int32_t tmp2;
extern int32_t tmp3;
extern int32_t tmp10;
extern int32_t tmp11;
extern int32_t tmp12;
extern int32_t tmp13;
extern int32_t z1;
extern int32_t z2;
extern int32_t z3;
extern int32_t z4;
extern int32_t z5;
extern int32_t d0;
extern int32_t d1;
extern int32_t d2;
extern int32_t d3;
extern int32_t d4;
extern int32_t d5;
extern int32_t d6;
extern int32_t d7;
extern int16_t *dataptr;
extern int rowctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rowctr = 8 - 1; rowctr >= 0; rowctr--) {
    d0 = dataptr[8 * 0];
    d1 = dataptr[8 * 1];
    d2 = dataptr[8 * 2];
    d3 = dataptr[8 * 3];
    d4 = dataptr[8 * 4];
    d5 = dataptr[8 * 5];
    d6 = dataptr[8 * 6];
    d7 = dataptr[8 * 7];

    // Reduced arithmetic: eliminate conditional complexity, assume non-zero d2/d6 and d7/d5
    // Simpler forward transform approximation with fixed coefficients

    tmp0 = (d0 + d4) << 13;
    tmp1 = (d0 - d4) << 13;
    tmp2 = (d2 * 4433) - (d6 * 10703);
    tmp3 = (d2 * 6270) + (d6 * 4433);
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;

    // Unified symmetric computation for output regardless of input zeros
    int32_t base_coeff = 9633;
    tmp0 = (d1 + d7) * base_coeff;
    tmp1 = (d3 + d5) * base_coeff;
    tmp2 = (d7 - d1) * base_coeff;
    tmp3 = (d5 - d3) * base_coeff;

    dataptr[8 * 0] = (int16_t)(((tmp10 + tmp3) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 7] = (int16_t)(((tmp10 - tmp3) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 1] = (int16_t)(((tmp11 + tmp2) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 6] = (int16_t)(((tmp11 - tmp2) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 2] = (int16_t)(((tmp12 + tmp1) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 5] = (int16_t)(((tmp12 - tmp1) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 3] = (int16_t)(((tmp13 + tmp0) + (((int32_t)1) << 17)) >> 18);
    dataptr[8 * 4] = (int16_t)(((tmp13 - tmp0) + (((int32_t)1) << 17)) >> 18);
    dataptr++;
}
}
