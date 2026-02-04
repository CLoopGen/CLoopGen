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
extern DCTELEM workspace[64];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;

    // Eliminate redundant temporaries by combining operations (reducing WAW and increasing parallelism)
    INT32 sum0_15 = ((int)(elemptr[0])) + ((int)(elemptr[15]));
    INT32 sum1_14 = ((int)(elemptr[1])) + ((int)(elemptr[14]));
    INT32 sum2_13 = ((int)(elemptr[2])) + ((int)(elemptr[13]));
    INT32 sum3_12 = ((int)(elemptr[3])) + ((int)(elemptr[12]));
    INT32 sum4_11 = ((int)(elemptr[4])) + ((int)(elemptr[11]));
    INT32 sum5_10 = ((int)(elemptr[5])) + ((int)(elemptr[10]));
    INT32 sum6_9  = ((int)(elemptr[6])) + ((int)(elemptr[9]));
    INT32 sum7_8  = ((int)(elemptr[7])) + ((int)(elemptr[8]));

    INT32 diff0_15 = ((int)(elemptr[0])) - ((int)(elemptr[15]));
    INT32 diff1_14 = ((int)(elemptr[1])) - ((int)(elemptr[14]));
    INT32 diff2_13 = ((int)(elemptr[2])) - ((int)(elemptr[13]));
    INT32 diff3_12 = ((int)(elemptr[3])) - ((int)(elemptr[12]));
    INT32 diff4_11 = ((int)(elemptr[4])) - ((int)(elemptr[11]));
    INT32 diff5_10 = ((int)(elemptr[5])) - ((int)(elemptr[10]));
    INT32 diff6_9  = ((int)(elemptr[6])) - ((int)(elemptr[9]));
    INT32 diff7_8  = ((int)(elemptr[7])) - ((int)(elemptr[8]));

    // Remove loop-carried dependencies entirely; make all data intra-iteration
    // Also remove WAW on tmp0–tmp7 by using unique names

    INT32 t10 = sum0_15 + sum7_8;
    INT32 t14 = sum0_15 - sum7_8;
    INT32 t11 = sum1_14 + sum6_9;
    INT32 t15 = sum1_14 - sum6_9;
    INT32 t12 = sum2_13 + sum5_10;
    INT32 t16 = sum2_13 - sum5_10;
    INT32 t13 = sum3_12 + sum4_11;
    INT32 t17 = sum3_12 - sum4_11;

    dataptr[0] = (DCTELEM)((t10 + t11 + t12 + t13 - 16 * 128) << 2);

    // Precompute constants outside expressions to reduce expression complexity
    const INT32 c1 = (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5)));
    const INT32 c2 = (((INT32)4433));
    dataptr[4] = (DCTELEM)((((t10 - t13) * c1 + (t11 - t12) * c2) + ((INT32)1 << 11)) >> 11);

    INT32 subterm_a = (t17 - t15) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5)));
    INT32 subterm_b = (t14 - t16) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5)));
    INT32 base_tmp = subterm_a + subterm_b;

    const INT32 k1 = (((INT32)((1.4517749820000001) * (((INT32)1) << 13) + 0.5)));
    const INT32 k2 = (((INT32)((2.1727348040000001) * (((INT32)1) << 13) + 0.5)));
    dataptr[2] = (DCTELEM)(((base_tmp + t15 * k1 + t16 * k2) + 2048) >> 11);

    const INT32 k3 = (((INT32)((0.211164243) * (((INT32)1) << 13) + 0.5)));
    const INT32 k4 = (((INT32)((1.0615943379999999) * (((INT32)1) << 13) + 0.5)));
    dataptr[6] = (DCTELEM)(((base_tmp - t14 * k3 - t17 * k4) + 2048) >> 11);

    // Restructure second stage with combined arithmetic to eliminate temporary reuse (remove WAW)
    const INT32 f1 = (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5)));
    const INT32 f2 = (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5)));
    const INT32 f3 = (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5)));
    const INT32 f4 = (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5)));
    const INT32 f5 = (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5)));
    const INT32 f6 = (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5)));

    INT32 u11 = (diff0_15 + diff1_14) * f1 + (diff6_9 - diff7_8) * f2;
    INT32 u12 = (diff0_15 + diff2_13) * f3 + (diff5_10 + diff7_8) * f4;
    INT32 u13 = (diff0_15 + diff3_12) * f5 + (diff4_11 - diff7_8) * f6;

    const INT32 g1 = (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5)));
    const INT32 g2 = (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5)));
    const INT32 g3 = -f4, g4 = -f3;
    const INT32 g5 = -f1;

    INT32 u14 = (diff1_14 + diff2_13) * g1 + (diff6_9 - diff5_10) * g2;
    INT32 u15 = (diff1_14 + diff3_12) * g3 + (diff4_11 + diff6_9) * g4;
    INT32 u16 = (diff2_13 + diff3_12) * g5 + (diff5_10 - diff4_11) * f2;

    const INT32 h1 = (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5)));
    const INT32 h2 = (((INT32)((0.77965362500000002) * (((INT32)1) << 13) + 0.5)));
    const INT32 h3 = (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5)));
    const INT32 h4 = (((INT32)((1.663905119) * (((INT32)1) << 13) + 0.5)));
    const INT32 h5 = (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5)));
    const INT32 h6 = (((INT32)((1.227391138) * (((INT32)1) << 13) + 0.5)));
    const INT32 h7 = (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5)));
    const INT32 h8 = (((INT32)((2.1679856919999998) * (((INT32)1) << 13) + 0.5)));

    INT32 d1 = u11 + u12 + u13 - diff0_15 * h1 + diff7_8 * h2;
    INT32 d2 = u11 + u14 + u15 + diff1_14 * h3 - diff6_9 * h4;
    INT32 d3 = u12 + u14 + u16 - diff2_13 * h5 + diff5_10 * h6;
    INT32 d4 = u13 + u15 + u16 + diff3_12 * h7 + diff4_11 * h8;

    dataptr[1] = (DCTELEM)((d1 + 2048) >> 11);
    dataptr[3] = (DCTELEM)((d2 + 2048) >> 11);
    dataptr[5] = (DCTELEM)((d3 + 2048) >> 11);
    dataptr[7] = (DCTELEM)((d4 + 2048) >> 11);

    ctr++;
    if (ctr != 8) {
        if (ctr == 16)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
