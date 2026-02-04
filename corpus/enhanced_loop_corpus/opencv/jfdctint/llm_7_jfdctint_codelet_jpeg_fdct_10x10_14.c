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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern DCTELEM workspace[16];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;

    // Reorder computations to eliminate some RAW hazards and introduce parallelism
    JSAMPLE val0 = elemptr[0], val1 = elemptr[1], val2 = elemptr[2], val3 = elemptr[3], val4 = elemptr[4];
    JSAMPLE val5 = elemptr[5], val6 = elemptr[6], val7 = elemptr[7], val8 = elemptr[8], val9 = elemptr[9];

    // Precompute differences and sums earlier, reduce re-reading from memory
    INT32 sum0_9 = ((int)val0) + ((int)val9);
    INT32 sum1_8 = ((int)val1) + ((int)val8);
    INT32 sum2_7 = ((int)val2) + ((int)val7);
    INT32 sum3_6 = ((int)val3) + ((int)val6);
    INT32 sum4_5 = ((int)val4) + ((int)val5);

    INT32 diff0_9 = ((int)val0) - ((int)val9);
    INT32 diff1_8 = ((int)val1) - ((int)val8);
    INT32 diff2_7 = ((int)val2) - ((int)val7);
    INT32 diff3_6 = ((int)val3) - ((int)val6);
    INT32 diff4_5 = ((int)val4) - ((int)val5);

    // Remove redundant recomputation by using precomputed values
    tmp10 = sum0_9 + sum4_5;
    tmp13 = sum0_9 - sum4_5;
    tmp11 = sum1_8 + sum3_6;
    tmp14 = sum1_8 - sum3_6;

    tmp0 = diff0_9;
    tmp1 = diff1_8;
    tmp2 = diff2_7;
    tmp3 = diff3_6;
    tmp4 = diff4_5;

    dataptr[0] = (DCTELEM)((tmp10 + tmp11 + sum2_7 - 10 * 128) << 1);
    INT32 scaled_sum2_7 = sum2_7 << 1;  // Replace tmp12 usage with local reuse

    const INT32 k1 = (INT32)((1.1441228059999999) * (1 << 13) + 0.5);
    const INT32 k2 = (INT32)((0.437016024) * (1 << 13) + 0.5);
    dataptr[4] = (DCTELEM)((((tmp10 - scaled_sum2_7) * k1 - (tmp11 - scaled_sum2_7) * k2) + (1 << 11)) >> 12);

    INT32 t10_14 = (tmp13 + tmp14);
    const INT32 k3 = (INT32)((0.831253876) * (1 << 13) + 0.5);
    const INT32 k4 = (INT32)((0.51374314799999998) * (1 << 13) + 0.5);
    const INT32 k5 = (INT32)((2.1762508989999998) * (1 << 13) + 0.5);
    INT32 base_val = t10_14 * k3;

    dataptr[2] = (DCTELEM)(((base_val + tmp13 * k4) + (1 << 11)) >> 12);
    dataptr[6] = (DCTELEM)(((base_val - tmp14 * k5) + (1 << 11)) >> 12);

    tmp10 = tmp0 + tmp4;
    tmp11 = tmp1 - tmp3;
    dataptr[5] = (DCTELEM)((tmp10 - tmp11 - tmp2) << 1);
    tmp2 <<= 13;

    const INT32 k6 = (INT32)((1.3968022470000001) * (1 << 13) + 0.5);
    const INT32 k7 = (INT32)((1.2600735110000001) * (1 << 13) + 0.5);
    const INT32 k8 = (INT32)((0.64203952200000003) * (1 << 13) + 0.5);
    const INT32 k9 = (INT32)((0.22123174200000001) * (1 << 13) + 0.5);
    dataptr[1] = (DCTELEM)(((tmp0 * k6 + tmp1 * k7 + tmp2 + tmp3 * k8 + tmp4 * k9) + (1 << 11)) >> 12);

    INT32 diff_diff = tmp0 - tmp4;
    INT32 sum_inner = tmp1 + tmp3;
    tmp12 = (diff_diff * (INT32)((0.95105651599999996) * (1 << 13) + 0.5)) - (sum_inner * (INT32)((0.58778525199999998) * (1 << 13) + 0.5));
    tmp13 = ((tmp10 + tmp11) * (INT32)((0.30901699399999999) * (1 << 13) + 0.5)) + (tmp11 << 12) - tmp2;

    dataptr[3] = (DCTELEM)(((tmp12 + tmp13) + (1 << 11)) >> 12);
    dataptr[7] = (DCTELEM)(((tmp12 - tmp13) + (1 << 11)) >> 12);

    // Eliminate loop-carried dependency entirely in this variant
    // No use of prior iteration's data in current computation

    ctr++;
    if (ctr != 8) {
        if (ctr == 10)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
