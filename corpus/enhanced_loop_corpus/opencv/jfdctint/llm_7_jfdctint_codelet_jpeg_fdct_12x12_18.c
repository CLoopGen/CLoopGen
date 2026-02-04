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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern DCTELEM workspace[32];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;

    // Eliminate some loop-carried dependencies by using local temporaries and reordering independent operations
    JSAMPLE val0 = elemptr[0], val1 = elemptr[1], val2 = elemptr[2], val3 = elemptr[3];
    JSAMPLE val4 = elemptr[4], val5 = elemptr[5], val6 = elemptr[6], val7 = elemptr[7];
    JSAMPLE val8 = elemptr[8], val9 = elemptr[9], val10 = elemptr[10], val11 = elemptr[11];

    // Reorder symmetric computations to expose parallelism
    INT32 sum_0_11 = ((int)val0) + ((int)val11);
    INT32 sum_1_10 = ((int)val1) + ((int)val10);
    INT32 sum_2_9  = ((int)val2) + ((int)val9);
    INT32 sum_3_8  = ((int)val3) + ((int)val8);
    INT32 sum_4_7  = ((int)val4) + ((int)val7);
    INT32 sum_5_6  = ((int)val5) + ((int)val6);

    INT32 diff_0_11 = ((int)val0) - ((int)val11);
    INT32 diff_1_10 = ((int)val1) - ((int)val10);
    INT32 diff_2_9  = ((int)val2) - ((int)val9);
    INT32 diff_3_8  = ((int)val3) - ((int)val8);
    INT32 diff_4_7  = ((int)val4) - ((int)val7);
    INT32 diff_5_6  = ((int)val5) - ((int)val6);

    // Break WAW hazard on tmp variables by assigning only once
    INT32 t10 = sum_0_11 + sum_5_6;
    INT32 t13 = sum_0_11 - sum_5_6;
    INT32 t11 = sum_1_10 + sum_4_7;
    INT32 t14 = sum_1_10 - sum_4_7;
    INT32 t12 = sum_2_9 + sum_3_8;
    INT32 t15 = sum_2_9 - sum_3_8;

    // Use separate identifiers to reduce false dependencies
    dataptr[0] = (DCTELEM)(t10 + t11 + t12 - 12 * 128);
    dataptr[6] = (DCTELEM)(t13 - t14 - t15);
    dataptr[4] = (DCTELEM)((((t10 - t12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 12)) >> 13);
    dataptr[2] = (DCTELEM)(((t14 - t15 + (t13 + t15) * (((INT32)((1.3660254039999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 12)) >> 13);

    // Precompute constants outside arithmetic expressions to reduce redundancy
    const INT32 C1 = ((INT32)((1.1219710540000001) * (((INT32)1) << 13) + 0.5));
    const INT32 C2 = ((INT32)((0.86091866900000003) * (((INT32)1) << 13) + 0.5));
    const INT32 C3 = ((INT32)((0.58077495300000004) * (((INT32)1) << 13) + 0.5));
    const INT32 C4 = ((INT32)((0.184591911) * (((INT32)1) << 13) + 0.5));
    const INT32 C5 = ((INT32)((2.339493912) * (((INT32)1) << 13) + 0.5));
    const INT32 C6 = ((INT32)((0.72578801100000001) * (((INT32)1) << 13) + 0.5));
    const INT32 C7 = ((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5));
    const INT32 C8 = 4433, C9 = 6270, C10 = 15137;

    INT32 partA = (diff_1_10 + diff_4_7) * C8;
    INT32 tmp14_new = partA + (diff_1_10 * C9);
    INT32 tmp15_new = partA - (diff_4_7 * C10);

    INT32 tmp12_new = (diff_0_11 + diff_2_9) * C1;
    INT32 tmp13_new = (diff_0_11 + diff_3_8) * C2;

    INT32 out1 = tmp12_new + tmp13_new + tmp14_new - (diff_0_11 * C3) + (diff_5_6 * C4);
    INT32 out3 = tmp15_new + ((diff_0_11 - diff_3_8) * C7) - ((diff_2_9 + diff_5_6) * C8);
    INT32 out5 = tmp12_new + ((diff_2_9 + diff_3_8) * (-C4)) - tmp15_new - (diff_2_9 * C5) + (diff_5_6 * C2);
    INT32 out7 = tmp13_new + ((diff_2_9 + diff_3_8) * (-C4)) - tmp14_new + (diff_3_8 * C6) - (diff_5_6 * C1);

    dataptr[1] = (DCTELEM)((out1 + (1 << 12)) >> 13);
    dataptr[3] = (DCTELEM)((out3 + (1 << 12)) >> 13);
    dataptr[5] = (DCTELEM)((out5 + (1 << 12)) >> 13);
    dataptr[7] = (DCTELEM)((out7 + (1 << 12)) >> 13);

    ctr++;
    if (ctr != 8) {
        if (ctr == 12)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
