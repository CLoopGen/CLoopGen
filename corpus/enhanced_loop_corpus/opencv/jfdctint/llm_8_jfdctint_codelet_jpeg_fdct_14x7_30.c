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
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 7; ctr++) {
    elemptr = sample_data[ctr] + start_col;

    // Reorder independent computations to change data flow and eliminate early WAW on tmp0, tmp1, etc.
    INT32 load0 = ((int)(elemptr[0]));
    INT32 load1 = ((int)(elemptr[1]));
    INT32 load2 = ((int)(elemptr[2]));
    INT32 load3 = ((int)(elemptr[3]));
    INT32 load4 = ((int)(elemptr[4]));
    INT32 load5 = ((int)(elemptr[5]));
    INT32 load6 = ((int)(elemptr[6]));
    INT32 load7 = ((int)(elemptr[7]));
    INT32 load8 = ((int)(elemptr[8]));
    INT32 load9 = ((int)(elemptr[9]));
    INT32 load10 = ((int)(elemptr[10]));
    INT32 load11 = ((int)(elemptr[11]));
    INT32 load12 = ((int)(elemptr[12]));
    INT32 load13 = ((int)(elemptr[13]));

    // Separate sum and difference calculations into distinct phases to reduce RAW stalls
    INT32 sum0_13 = load0 + load13;
    INT32 sum1_12 = load1 + load12;
    INT32 sum2_11 = load2 + load11;
    INT32 sum3_10 = load3 + load10;
    INT32 sum4_9 = load4 + load9;
    INT32 sum5_8 = load5 + load8;
    INT32 sum6_7 = load6 + load7;

    INT32 diff0_13 = load0 - load13;
    INT32 diff1_12 = load1 - load12;
    INT32 diff2_11 = load2 - load11;
    INT32 diff3_10 = load3 - load10;
    INT32 diff4_9 = load4 - load9;
    INT32 diff5_8 = load5 - load8;
    INT32 diff6_7 = load6 - load7;

    // Assign to temporaries only after all loads and arithmetic to minimize false dependencies
    tmp0 = sum0_13;
    tmp1 = sum1_12;
    tmp2 = sum2_11;
    tmp13 = sum3_10;
    tmp4 = sum4_9;
    tmp5 = sum5_8;
    tmp6 = sum6_7;

    tmp10 = tmp0 + tmp6;
    tmp14 = tmp0 - tmp6;
    tmp11 = tmp1 + tmp5;
    tmp15 = tmp1 - tmp5;
    tmp12 = tmp2 + tmp4;
    tmp16 = tmp2 - tmp4;

    // Now reassign for differences without overwriting prematurely
    tmp0 = diff0_13;
    tmp1 = diff1_12;
    tmp2 = diff2_11;
    tmp3 = diff3_10;
    tmp4 = diff4_9;
    tmp5 = diff5_8;
    tmp6 = diff6_7;

    dataptr[0] = (DCTELEM)((tmp10 + tmp11 + tmp12 + tmp13 - 14 * 128) << 2);
    tmp13 += tmp13;

    // Fold constants where possible and preserve operation semantics
    const INT32 c1 = (INT32)((1.274162392) * (((INT32)1) << 13) + 0.5);
    const INT32 c2 = (INT32)((0.31469212299999999) * (((INT32)1) << 13) + 0.5);
    const INT32 c3 = (INT32)((0.88174773399999995) * (((INT32)1) << 13) + 0.5);
    const INT32 shift_adj = ((INT32)1 << ((13 - 2) - 1));

    dataptr[4] = (DCTELEM)((((tmp10 - tmp13) * c1 + (tmp11 - tmp13) * c2 - (tmp12 - tmp13) * c3) + shift_adj) >> (13 - 2));

    INT32 base_factor = ((tmp14 + tmp15) * (INT32)((1.105676686) * (((INT32)1) << 13) + 0.5));
    const INT32 f1 = (INT32)((0.27307958999999998) * (((INT32)1) << 13) + 0.5);
    const INT32 f2 = (INT32)((0.61360426800000001) * (((INT32)1) << 13) + 0.5);
    const INT32 f3 = (INT32)((1.719280954) * (((INT32)1) << 13) + 0.5);
    const INT32 f4 = (INT32)((1.3787562760000001) * (((INT32)1) << 13) + 0.5);

    dataptr[2] = (DCTELEM)(((base_factor + tmp14 * f1 + tmp16 * f2) + shift_adj) >> (13 - 2));
    dataptr[6] = (DCTELEM)(((base_factor - tmp15 * f3 - tmp16 * f4) + shift_adj) >> (13 - 2));

    INT32 partA = tmp1 + tmp2;
    INT32 partB = tmp5 - tmp4;
    dataptr[7] = (DCTELEM)((tmp0 - partA + tmp3 - partB - tmp6) << 2);

    tmp3 <<= 13;
    INT32 termA = partA * (-(INT32)((0.15834168100000001) * (((INT32)1) << 13) + 0.5));
    INT32 termB = partB * (INT32)((1.405321284) * (((INT32)1) << 13) + 0.5);
    INT32 combined = termA + termB - tmp3;

    INT32 subexpr1 = (tmp0 + tmp2) * (INT32)((1.1974488459999999) * (((INT32)1) << 13) + 0.5);
    INT32 subexpr2 = (tmp4 + tmp6) * (INT32)((0.752406978) * (((INT32)1) << 13) + 0.5);
    INT32 total1 = subexpr1 + subexpr2;

    dataptr[5] = (DCTELEM)(((combined + total1 - tmp2 * (INT32)((2.3739597730000002) * (((INT32)1) << 13) + 0.5) + tmp4 * (INT32)((1.119999435) * (((INT32)1) << 13) + 0.5)) + shift_adj) >> (13 - 2));

    INT32 cross1 = (tmp0 + tmp1) * (INT32)((1.334852607) * (((INT32)1) << 13) + 0.5);
    INT32 cross2 = (tmp5 - tmp6) * (INT32)((0.46708512899999999) * (((INT32)1) << 13) + 0.5);
    INT32 total2 = cross1 + cross2;

    dataptr[3] = (DCTELEM)(((combined + total2 - tmp1 * (INT32)((0.42410394800000001) * (((INT32)1) << 13) + 0.5) - tmp5 * (INT32)((3.0698552590000001) * (((INT32)1) << 13) + 0.5)) + shift_adj) >> (13 - 2));
    dataptr[1] = (DCTELEM)(((total1 + total2 + tmp3 + tmp6 - (tmp0 + tmp6) * (INT32)((1.1269801690000001) * (((INT32)1) << 13) + 0.5)) + shift_adj) >> (13 - 2));

    dataptr += 8;
}
}
