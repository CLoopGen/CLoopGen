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
extern INT32 tmp7;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern INT32 tmp17;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 8; ctr++) {
        elemptr = sample_data[ctr] + start_col;

        // Eliminate redundant temporaries and inline expressions to reduce WAW and WAR hazards
        INT32 s0 = ((int)(elemptr[0])),  s1 = ((int)(elemptr[1])),  s2 = ((int)(elemptr[2])),  s3 = ((int)(elemptr[3]));
        INT32 s4 = ((int)(elemptr[4])),  s5 = ((int)(elemptr[5])),  s6 = ((int)(elemptr[6])),  s7 = ((int)(elemptr[7]));
        INT32 s8 = ((int)(elemptr[8])),  s9 = ((int)(elemptr[9])),  s10 = ((int)(elemptr[10])), s11 = ((int)(elemptr[11]));
        INT32 s12 = ((int)(elemptr[12])), s13 = ((int)(elemptr[13])), s14 = ((int)(elemptr[14])), s15 = ((int)(elemptr[15]));

        INT32 sum0_15 = s0 + s15, sum1_14 = s1 + s14, sum2_13 = s2 + s13, sum3_12 = s3 + s12;
        INT32 sum4_11 = s4 + s11, sum5_10 = s5 + s10, sum6_9 = s6 + s9, sum7_8 = s7 + s8;

        INT32 diff0_15 = s0 - s15, diff1_14 = s1 - s14, diff2_13 = s2 - s13, diff3_12 = s3 - s12;
        INT32 diff4_11 = s4 - s11, diff5_10 = s5 - s10, diff6_9 = s6 - s9, diff7_8 = s7 - s8;

        // Combine symmetric terms directly without intermediate tmp variables to reduce dependencies
        INT32 A0 = sum0_15 + sum7_8;
        INT32 A1 = sum1_14 + sum6_9;
        INT32 A2 = sum2_13 + sum5_10;
        INT32 A3 = sum3_12 + sum4_11;

        dataptr[0] = (DCTELEM)(((A0 + A1 + A2 + A3 - 16 * 128)) << 2);

        // Fully compute stage 4 without storing in tmp4 to eliminate WAW
        INT32 coeff1 = (INT32)(1.3065629649999999 * (1 << 13) + 0.5);
        INT32 coeff2 = 4433;
        dataptr[4] = (DCTELEM)((((A0 - A3) * coeff1 + (A1 - A2) * coeff2 + (1 << 10)) >> 11));

        // Fuse butterfly calculations with immediate use — no loop-carried dependency
        INT32 B0 = sum0_15 - sum7_8;
        INT32 B1 = sum1_14 - sum6_9;
        INT32 B2 = sum2_13 - sum5_10;
        INT32 B3 = sum3_12 - sum4_11;

        INT32 C0 = (B3 - B1) * (INT32)(0.275899379 * (1 << 13) + 0.5) +
                   (B0 - B2) * (INT32)(1.3870398450000001 * (1 << 13) + 0.5);

        INT32 fixed_shift = (1 << 10);
        dataptr[2] = (DCTELEM)(((C0 + B1 * (INT32)(1.4517749820000001 * (1 << 13) + 0.5) +
                                 B2 * (INT32)(2.1727348040000001 * (1 << 13) + 0.5) + fixed_shift) >> 11));
        dataptr[6] = (DCTELEM)(((C0 - B0 * (INT32)(0.211164243 * (1 << 13) + 0.5) -
                                 B3 * (INT32)(1.0615943379999999 * (1 << 13) + 0.5) + fixed_shift) >> 11));

        // Use direct arithmetic on differences to avoid reuse of tmp0-tmp7
        INT32 D0 = (diff0_15 + diff1_14) * (INT32)(1.3533180010000001 * (1 << 13) + 0.5) +
                   (diff6_9 - diff7_8) * (INT32)(0.410524528 * (1 << 13) + 0.5);
        INT32 D1 = (diff0_15 + diff2_13) * (INT32)(1.247225013 * (1 << 13) + 0.5) +
                   (diff5_10 + diff7_8) * (INT32)(0.66665565800000004 * (1 << 13) + 0.5);
        INT32 D2 = (diff0_15 + diff3_12) * (INT32)(1.0932018670000001 * (1 << 13) + 0.5) +
                   (diff4_11 - diff7_8) * (INT32)(0.89716758600000002 * (1 << 13) + 0.5);
        INT32 D3 = (diff1_14 + diff2_13) * (INT32)(0.13861716900000001 * (1 << 13) + 0.5) +
                   (diff6_9 - diff5_10) * (INT32)(1.407403738 * (1 << 13) + 0.5);
        INT32 D4 = (diff1_14 + diff3_12) * (-(INT32)(0.66665565800000004 * (1 << 13) + 0.5)) +
                   (diff4_11 + diff6_9) * (-(INT32)(1.247225013 * (1 << 13) + 0.5));
        INT32 D5 = (diff2_13 + diff3_12) * (-(INT32)(1.3533180010000001 * (1 << 13) + 0.5)) +
                   (diff5_10 - diff4_11) * (INT32)(0.410524528 * (1 << 13) + 0.5);

        INT32 E0 = D0 + D1 + D2 - diff0_15 * (INT32)(2.2863411440000001 * (1 << 13) + 0.5) +
                   diff7_8 * (INT32)(0.77965362500000002 * (1 << 13) + 0.5);
        INT32 E1 = D0 + D3 + D4 + diff1_14 * (INT32)(0.071888073999999996 * (1 << 13) + 0.5) -
                   diff6_9 * (INT32)(1.663905119 * (1 << 13) + 0.5);
        INT32 E2 = D1 + D3 + D5 - diff2_13 * (INT32)(1.125726048 * (1 << 13) + 0.5) +
                   diff5_10 * (INT32)(1.227391138 * (1 << 13) + 0.5);
        INT32 E3 = D2 + D4 + D5 + diff3_12 * (INT32)(1.0653889620000001 * (1 << 13) + 0.5) +
                   diff4_11 * (INT32)(2.1679856919999998 * (1 << 13) + 0.5);

        dataptr[1] = (DCTELEM)((E0 + fixed_shift) >> 11);
        dataptr[3] = (DCTELEM)((E1 + fixed_shift) >> 11);
        dataptr[5] = (DCTELEM)((E2 + fixed_shift) >> 11);
        dataptr[7] = (DCTELEM)((E3 + fixed_shift) >> 11);

        dataptr += 8;
    }
}
