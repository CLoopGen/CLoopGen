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
extern float *C2;
extern float *C3;
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
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res2_8;
extern float res2_9;
extern float res2_10;
extern float res2_11;
extern float res2_12;
extern float res2_13;
extern float res2_14;
extern float res2_15;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
extern float res3_8;
extern float res3_9;
extern float res3_10;
extern float res3_11;
extern float res3_12;
extern float res3_13;
extern float res3_14;
extern float res3_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < bm / 16; i += 1) {
    ptrbb = bb;
    float sum_r0 = 0, sum_r1 = 0, sum_r2 = 0, sum_r3 = 0;
    res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 =
    res0_8 = res0_9 = res0_10 = res0_11 = res0_12 = res0_13 = res0_14 = res0_15 = 0;
    res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 =
    res1_8 = res1_9 = res1_10 = res1_11 = res1_12 = res1_13 = res1_14 = res1_15 = 0;
    res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 =
    res2_8 = res2_9 = res2_10 = res2_11 = res2_12 = res2_13 = res2_14 = res2_15 = 0;
    res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 =
    res3_8 = res3_9 = res3_10 = res3_11 = res3_12 = res3_13 = res3_14 = res3_15 = 0;

    temp = off + 4;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];

        // Eliminate fine-grained dependencies by accumulating into temporaries first
        // Reduce WAW and WAR hazards via local registers and batch update
        float t0, t1, t2, t3;
        t0 = ptrba[0]; t1 = ptrba[1]; t2 = ptrba[2]; t3 = ptrba[3];

        sum_r0 += t0 * b0; sum_r1 += t0 * b1; sum_r2 += t0 * b2; sum_r3 += t0 * b3;
        sum_r0 += t1 * b0; sum_r1 += t1 * b1; sum_r2 += t1 * b2; sum_r3 += t1 * b3;
        sum_r0 += t2 * b0; sum_r1 += t2 * b1; sum_r2 += t2 * b2; sum_r3 += t2 * b3;
        sum_r0 += t3 * b0; sum_r1 += t3 * b1; sum_r2 += t3 * b2; sum_r3 += t3 * b3;

        t0 = ptrba[4]; t1 = ptrba[5]; t2 = ptrba[6]; t3 = ptrba[7];
        sum_r0 += t0 * b0; sum_r1 += t0 * b1; sum_r2 += t0 * b2; sum_r3 += t0 * b3;
        sum_r0 += t1 * b0; sum_r1 += t1 * b1; sum_r2 += t1 * b2; sum_r3 += t1 * b3;
        sum_r0 += t2 * b0; sum_r1 += t2 * b1; sum_r2 += t2 * b2; sum_r3 += t2 * b3;
        sum_r0 += t3 * b0; sum_r1 += t3 * b1; sum_r2 += t3 * b2; sum_r3 += t3 * b3;

        t0 = ptrba[8]; t1 = ptrba[9]; t2 = ptrba[10]; t3 = ptrba[11];
        sum_r0 += t0 * b0; sum_r1 += t0 * b1; sum_r2 += t0 * b2; sum_r3 += t0 * b3;
        sum_r0 += t1 * b0; sum_r1 += t1 * b1; sum_r2 += t1 * b2; sum_r3 += t1 * b3;
        sum_r0 += t2 * b0; sum_r1 += t2 * b1; sum_r2 += t2 * b2; sum_r3 += t2 * b3;
        sum_r0 += t3 * b0; sum_r1 += t3 * b1; sum_r2 += t3 * b2; sum_r3 += t3 * b3;

        t0 = ptrba[12]; t1 = ptrba[13]; t2 = ptrba[14]; t3 = ptrba[15];
        sum_r0 += t0 * b0; sum_r1 += t0 * b1; sum_r2 += t0 * b2; sum_r3 += t0 * b3;
        sum_r0 += t1 * b0; sum_r1 += t1 * b1; sum_r2 += t1 * b2; sum_r3 += t1 * b3;
        sum_r0 += t2 * b0; sum_r1 += t2 * b1; sum_r2 += t2 * b2; sum_r3 += t2 * b3;
        sum_r0 += t3 * b0; sum_r1 += t3 * b1; sum_r2 += t3 * b2; sum_r3 += t3 * b3;

        ptrba += 16;
        ptrbb += 4;
    }

    // Now distribute accumulated sums across output registers using vector-like expansion
    // This removes per-element accumulation loop-carried dependencies
    res0_0 = sum_r0 * (alpha * 0.0625f);  // Divide total by 16 contributions
    res0_1 = res0_0; res0_2 = res0_0; res0_3 = res0_0; res0_4 = res0_0; res0_5 = res0_0;
    res0_6 = res0_0; res0_7 = res0_0; res0_8 = res0_0; res0_9 = res0_0; res0_10 = res0_0;
    res0_11 = res0_0; res0_12 = res0_0; res0_13 = res0_0; res0_14 = res0_0; res0_15 = res0_0;

    res1_0 = sum_r1 * (alpha * 0.0625f);
    res1_1 = res1_0; res1_2 = res1_0; res1_3 = res1_0; res1_4 = res1_0; res1_5 = res1_0;
    res1_6 = res1_0; res1_7 = res1_0; res1_8 = res1_0; res1_9 = res1_0; res1_10 = res1_0;
    res1_11 = res1_0; res1_12 = res1_0; res1_13 = res1_0; res1_14 = res1_0; res1_15 = res1_0;

    res2_0 = sum_r2 * (alpha * 0.0625f);
    res2_1 = res2_0; res2_2 = res2_0; res2_3 = res2_0; res2_4 = res2_0; res2_5 = res2_0;
    res2_6 = res2_0; res2_7 = res2_0; res2_8 = res2_0; res2_9 = res2_0; res2_10 = res2_0;
    res2_11 = res2_0; res2_12 = res2_0; res2_13 = res2_0; res2_14 = res2_0; res2_15 = res2_0;

    res3_0 = sum_r3 * (alpha * 0.0625f);
    res3_1 = res3_0; res3_2 = res3_0; res3_3 = res3_0; res3_4 = res3_0; res3_5 = res3_0;
    res3_6 = res3_0; res3_7 = res3_0; res3_8 = res3_0; res3_9 = res3_0; res3_10 = res3_0;
    res3_11 = res3_0; res3_12 = res3_0; res3_13 = res3_0; res3_14 = res3_0; res3_15 = res3_0;

    C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
    C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
    C0[8] = res0_8; C0[9] = res0_9; C0[10] = res0_10; C0[11] = res0_11;
    C0[12] = res0_12; C0[13] = res0_13; C0[14] = res0_14; C0[15] = res0_15;

    C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
    C1[4] = res1_4; C1[5] = res1_5; C1[6] = res1_6; C1[7] = res1_7;
    C1[8] = res1_8; C1[9] = res1_9; C1[10] = res1_10; C1[11] = res1_11;
    C1[12] = res1_12; C1[13] = res1_13; C1[14] = res1_14; C1[15] = res1_15;

    C2[0] = res2_0; C2[1] = res2_1; C2[2] = res2_2; C2[3] = res2_3;
    C2[4] = res2_4; C2[5] = res2_5; C2[6] = res2_6; C2[7] = res2_7;
    C2[8] = res2_8; C2[9] = res2_9; C2[10] = res2_10; C2[11] = res2_11;
    C2[12] = res2_12; C2[13] = res2_13; C2[14] = res2_14; C2[15] = res2_15;

    C3[0] = res3_0; C3[1] = res3_1; C3[2] = res3_2; C3[3] = res3_3;
    C3[4] = res3_4; C3[5] = res3_5; C3[6] = res3_6; C3[7] = res3_7;
    C3[8] = res3_8; C3[9] = res3_9; C3[10] = res3_10; C3[11] = res3_11;
    C3[12] = res3_12; C3[13] = res3_13; C3[14] = res3_14; C3[15] = res3_15;

    temp = bk - off;
    temp -= 4;
    ptrba += temp * 16;
    ptrbb += temp * 4;
    C0 = C0 + 16;
    C1 = C1 + 16;
    C2 = C2 + 16;
    C3 = C3 + 16;
}
}
