#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bk;
extern float alpha;
extern float *bb;
extern BLASLONG i;
extern BLASLONG k;
extern float *C0;
extern float *C1;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res0_4;
extern float res0_5;
extern float res0_6;
extern float res0_7;
extern float res0_8;
extern float res0_9;
extern float res0_10;
extern float res0_11;
extern float res0_12;
extern float res0_13;
extern float res0_14;
extern float res0_15;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res1_8;
extern float res1_9;
extern float res1_10;
extern float res1_11;
extern float res1_12;
extern float res1_13;
extern float res1_14;
extern float res1_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < bm / 16; i += 1) {
    ptrbb = bb;
    res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 =
    res0_8 = res0_9 = res0_10 = res0_11 = res0_12 = res0_13 = res0_14 = res0_15 = 0;
    res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 =
    res1_8 = res1_9 = res1_10 = res1_11 = res1_12 = res1_13 = res1_14 = res1_15 = 0;

    temp = off + 2;
    k = 0;
    if (temp > 0) {
        do {
            b0 = ptrbb[0];
            b1 = ptrbb[1];

            a0 = ptrba[0]; res0_0 += a0 * b0; res1_0 += a0 * b1;
            a1 = ptrba[1]; res0_1 += a1 * b0; res1_1 += a1 * b1;
            a0 = ptrba[2]; res0_2 += a0 * b0; res1_2 += a0 * b1;
            a1 = ptrba[3]; res0_3 += a1 * b0; res1_3 += a1 * b1;
            a0 = ptrba[4]; res0_4 += a0 * b0; res1_4 += a0 * b1;
            a1 = ptrba[5]; res0_5 += a1 * b0; res1_5 += a1 * b1;
            a0 = ptrba[6]; res0_6 += a0 * b0; res1_6 += a0 * b1;
            a1 = ptrba[7]; res0_7 += a1 * b0; res1_7 += a1 * b1;
            a0 = ptrba[8]; res0_8 += a0 * b0; res1_8 += a0 * b1;
            a1 = ptrba[9]; res0_9 += a1 * b0; res1_9 += a1 * b1;
            a0 = ptrba[10]; res0_10 += a0 * b0; res1_10 += a0 * b1;
            a1 = ptrba[11]; res0_11 += a1 * b0; res1_11 += a1 * b1;
            a0 = ptrba[12]; res0_12 += a0 * b0; res1_12 += a0 * b1;
            a1 = ptrba[13]; res0_13 += a1 * b0; res1_13 += a1 * b1;
            a0 = ptrba[14]; res0_14 += a0 * b0; res1_14 += a0 * b1;
            a1 = ptrba[15]; res0_15 += a1 * b0; res1_15 += a1 * b1;

            ptrba += 16;
            ptrbb += 2;
            k++;
        } while (k < temp);
    }

    float scaled_alpha = alpha;
    res0_0 *= scaled_alpha; res0_1 *= scaled_alpha; res0_2 *= scaled_alpha; res0_3 *= scaled_alpha;
    res0_4 *= scaled_alpha; res0_5 *= scaled_alpha; res0_6 *= scaled_alpha; res0_7 *= scaled_alpha;
    res0_8 *= scaled_alpha; res0_9 *= scaled_alpha; res0_10 *= scaled_alpha; res0_11 *= scaled_alpha;
    res0_12 *= scaled_alpha; res0_13 *= scaled_alpha; res0_14 *= scaled_alpha; res0_15 *= scaled_alpha;
    res1_0 *= scaled_alpha; res1_1 *= scaled_alpha; res1_2 *= scaled_alpha; res1_3 *= scaled_alpha;
    res1_4 *= scaled_alpha; res1_5 *= scaled_alpha; res1_6 *= scaled_alpha; res1_7 *= scaled_alpha;
    res1_8 *= scaled_alpha; res1_9 *= scaled_alpha; res1_10 *= scaled_alpha; res1_11 *= scaled_alpha;
    res1_12 *= scaled_alpha; res1_13 *= scaled_alpha; res1_14 *= scaled_alpha; res1_15 *= scaled_alpha;

    float *dst0 = C0, *dst1 = C1;
    dst0[0] = res0_0;   dst0[1] = res0_1;   dst0[2] = res0_2;   dst0[3] = res0_3;
    dst0[4] = res0_4;   dst0[5] = res0_5;   dst0[6] = res0_6;   dst0[7] = res0_7;
    dst0[8] = res0_8;   dst0[9] = res0_9;   dst0[10] = res0_10; dst0[11] = res0_11;
    dst0[12] = res0_12; dst0[13] = res0_13; dst0[14] = res0_14; dst0[15] = res0_15;
    dst1[0] = res1_0;   dst1[1] = res1_1;   dst1[2] = res1_2;   dst1[3] = res1_3;
    dst1[4] = res1_4;   dst1[5] = res1_5;   dst1[6] = res1_6;   dst1[7] = res1_7;
    dst1[8] = res1_8;   dst1[9] = res1_9;   dst1[10] = res1_10; dst1[11] = res1_11;
    dst1[12] = res1_12; dst1[13] = res1_13; dst1[14] = res1_14; dst1[15] = res1_15;

    temp = bk - off - 2;
    ptrba += temp * 16;
    ptrbb += temp * 2;
    C0 += 16;
    C1 += 16;
}
}
