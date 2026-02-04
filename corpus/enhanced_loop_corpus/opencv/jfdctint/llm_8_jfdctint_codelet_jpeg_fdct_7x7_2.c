#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 7; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    INT32 val0 = (int)(elemptr[0]);
    INT32 val1 = (int)(elemptr[1]);
    INT32 val2 = (int)(elemptr[2]);
    INT32 val3 = (int)(elemptr[3]);
    INT32 val4 = (int)(elemptr[4]);
    INT32 val5 = (int)(elemptr[5]);
    INT32 val6 = (int)(elemptr[6]);

    tmp0 = val0 + val6;
    tmp1 = val1 + val5;
    tmp2 = val2 + val4;
    tmp3 = val3;

    tmp10 = val0 - val6;
    tmp11 = val1 - val5;
    tmp12 = val2 - val4;

    z1 = tmp0 + tmp2;
    z2 = tmp0 - tmp2;
    z3 = tmp1 - tmp2;

    dataptr[0] = (DCTELEM)((z1 + tmp1 + tmp3 - 7 * 128) << 2);

    tmp3 <<= 1;
    z1 -= 2 * tmp3;

    INT32 factor_z1 = ((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5));
    INT32 factor_z2 = ((INT32)((0.92060900199999995) * (((INT32)1) << 13) + 0.5));
    INT32 factor_z3 = ((INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5));

    z1 = z1 * factor_z1;
    z2 = z2 * factor_z2;
    z3 = z3 * factor_z3;

    dataptr[2] = (DCTELEM)(((z1 + z2 + z3) + ((INT32)1 << 10)) >> 11);

    z1 -= z2;

    INT32 diff_tmp0_tmp1 = tmp0 - tmp1;
    INT32 factor_diff = ((INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5));
    z2 = diff_tmp0_tmp1 * factor_diff;

    INT32 diff_tmp1_tmp3 = tmp1 - tmp3;
    INT32 factor_sqrt_half = ((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5));
    INT32 cross_term = diff_tmp1_tmp3 * factor_sqrt_half;

    dataptr[4] = (DCTELEM)(((z2 + z3 - cross_term) + ((INT32)1 << 10)) >> 11);
    dataptr[6] = (DCTELEM)(((z1 + z2) + ((INT32)1 << 10)) >> 11);

    INT32 sum10_11 = tmp10 + tmp11;
    INT32 diff10_11 = tmp10 - tmp11;
    INT32 sum11_12 = tmp11 + tmp12;
    INT32 sum10_12 = tmp10 + tmp12;

    tmp1 = sum10_11 * ((INT32)((0.93541434700000003) * (((INT32)1) << 13) + 0.5));
    tmp2 = diff10_11 * ((INT32)((0.17026233900000001) * (((INT32)1) << 13) + 0.5));

    tmp0 = tmp1 - tmp2;
    tmp1 += tmp2;

    tmp2 += sum11_12 * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5)));
    tmp1 += sum11_12 * (-((INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5)));

    tmp3 = sum10_12 * ((INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5));
    tmp0 += tmp3;
    tmp2 += tmp3 + (tmp12 * ((INT32)((1.870828693) * (((INT32)1) << 13) + 0.5)));

    dataptr[1] = (DCTELEM)(((tmp0) + ((INT32)1 << 10)) >> 11);
    dataptr[3] = (DCTELEM)(((tmp1) + ((INT32)1 << 10)) >> 11);
    dataptr[5] = (DCTELEM)(((tmp2) + ((INT32)1 << 10)) >> 11);

    dataptr += 8;
}
}
