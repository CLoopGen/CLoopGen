#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bn;
extern BLASLONG bk;
extern float alpha;
extern float *ba;
extern float *bb;
extern float *C;
extern BLASLONG ldc;
extern BLASLONG i;
extern BLASLONG j;
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
for (j = 0; j < bn / 4; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C0 + 2 * ldc;
    C3 = C0 + 3 * ldc;
    ptrba = ba;
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 =
        res0_8 = res0_9 = res0_10 = res0_11 = res0_12 = res0_13 = res0_14 = res0_15 =
        res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 =
        res1_8 = res1_9 = res1_10 = res1_11 = res1_12 = res1_13 = res1_14 = res1_15 =
        res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 =
        res2_8 = res2_9 = res2_10 = res2_11 = res2_12 = res2_13 = res2_14 = res2_15 =
        res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 =
        res3_8 = res3_9 = res3_10 = res3_11 = res3_12 = res3_13 = res3_14 = res3_15 = 0.0f;

        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];

            res0_0 += ptrba[0] * b0; res1_0 += ptrba[0] * b1; res2_0 += ptrba[0] * b2; res3_0 += ptrba[0] * b3;
            res0_1 += ptrba[1] * b0; res1_1 += ptrba[1] * b1; res2_1 += ptrba[1] * b2; res3_1 += ptrba[1] * b3;
            res0_2 += ptrba[2] * b0; res1_2 += ptrba[2] * b1; res2_2 += ptrba[2] * b2; res3_2 += ptrba[2] * b3;
            res0_3 += ptrba[3] * b0; res1_3 += ptrba[3] * b1; res2_3 += ptrba[3] * b2; res3_3 += ptrba[3] * b3;
            res0_4 += ptrba[4] * b0; res1_4 += ptrba[4] * b1; res2_4 += ptrba[4] * b2; res3_4 += ptrba[4] * b3;
            res0_5 += ptrba[5] * b0; res1_5 += ptrba[5] * b1; res2_5 += ptrba[5] * b2; res3_5 += ptrba[5] * b3;
            res0_6 += ptrba[6] * b0; res1_6 += ptrba[6] * b1; res2_6 += ptrba[6] * b2; res3_6 += ptrba[6] * b3;
            res0_7 += ptrba[7] * b0; res1_7 += ptrba[7] * b1; res2_7 += ptrba[7] * b2; res3_7 += ptrba[7] * b3;
            res0_8 += ptrba[8] * b0; res1_8 += ptrba[8] * b1; res2_8 += ptrba[8] * b2; res3_8 += ptrba[8] * b3;
            res0_9 += ptrba[9] * b0; res1_9 += ptrba[9] * b1; res2_9 += ptrba[9] * b2; res3_9 += ptrba[9] * b3;
            res0_10 += ptrba[10] * b0; res1_10 += ptrba[10] * b1; res2_10 += ptrba[10] * b2; res3_10 += ptrba[10] * b3;
            res0_11 += ptrba[11] * b0; res1_11 += ptrba[11] * b1; res2_11 += ptrba[11] * b2; res3_11 += ptrba[11] * b3;
            res0_12 += ptrba[12] * b0; res1_12 += ptrba[12] * b1; res2_12 += ptrba[12] * b2; res3_12 += ptrba[12] * b3;
            res0_13 += ptrba[13] * b0; res1_13 += ptrba[13] * b1; res2_13 += ptrba[13] * b2; res3_13 += ptrba[13] * b3;
            res0_14 += ptrba[14] * b0; res1_14 += ptrba[14] * b1; res2_14 += ptrba[14] * b2; res3_14 += ptrba[14] * b3;
            res0_15 += ptrba[15] * b0; res1_15 += ptrba[15] * b1; res2_15 += ptrba[15] * b2; res3_15 += ptrba[15] * b3;

            ptrba += 16;
            ptrbb += 4;
        }

        float scaled_alpha = alpha;
        C0[0] = res0_0 * scaled_alpha; C0[1] = res0_1 * scaled_alpha; C0[2] = res0_2 * scaled_alpha; C0[3] = res0_3 * scaled_alpha;
        C0[4] = res0_4 * scaled_alpha; C0[5] = res0_5 * scaled_alpha; C0[6] = res0_6 * scaled_alpha; C0[7] = res0_7 * scaled_alpha;
        C0[8] = res0_8 * scaled_alpha; C0[9] = res0_9 * scaled_alpha; C0[10] = res0_10 * scaled_alpha; C0[11] = res0_11 * scaled_alpha;
        C0[12] = res0_12 * scaled_alpha; C0[13] = res0_13 * scaled_alpha; C0[14] = res0_14 * scaled_alpha; C0[15] = res0_15 * scaled_alpha;

        C1[0] = res1_0 * scaled_alpha; C1[1] = res1_1 * scaled_alpha; C1[2] = res1_2 * scaled_alpha; C1[3] = res1_3 * scaled_alpha;
        C1[4] = res1_4 * scaled_alpha; C1[5] = res1_5 * scaled_alpha; C1[6] = res1_6 * scaled_alpha; C1[7] = res1_7 * scaled_alpha;
        C1[8] = res1_8 * scaled_alpha; C1[9] = res1_9 * scaled_alpha; C1[10] = res1_10 * scaled_alpha; C1[11] = res1_11 * scaled_alpha;
        C1[12] = res1_12 * scaled_alpha; C1[13] = res1_13 * scaled_alpha; C1[14] = res1_14 * scaled_alpha; C1[15] = res1_15 * scaled_alpha;

        C2[0] = res2_0 * scaled_alpha; C2[1] = res2_1 * scaled_alpha; C2[2] = res2_2 * scaled_alpha; C2[3] = res2_3 * scaled_alpha;
        C2[4] = res2_4 * scaled_alpha; C2[5] = res2_5 * scaled_alpha; C2[6] = res2_6 * scaled_alpha; C2[7] = res2_7 * scaled_alpha;
        C2[8] = res2_8 * scaled_alpha; C2[9] = res2_9 * scaled_alpha; C2[10] = res2_10 * scaled_alpha; C2[11] = res2_11 * scaled_alpha;
        C2[12] = res2_12 * scaled_alpha; C2[13] = res2_13 * scaled_alpha; C2[14] = res2_14 * scaled_alpha; C2[15] = res2_15 * scaled_alpha;

        C3[0] = res3_0 * scaled_alpha; C3[1] = res3_1 * scaled_alpha; C3[2] = res3_2 * scaled_alpha; C3[3] = res3_3 * scaled_alpha;
        C3[4] = res3_4 * scaled_alpha; C3[5] = res3_5 * scaled_alpha; C3[6] = res3_6 * scaled_alpha; C3[7] = res3_7 * scaled_alpha;
        C3[8] = res3_8 * scaled_alpha; C3[9] = res3_9 * scaled_alpha; C3[10] = res3_10 * scaled_alpha; C3[11] = res3_11 * scaled_alpha;
        C3[12] = res3_12 * scaled_alpha; C3[13] = res3_13 * scaled_alpha; C3[14] = res3_14 * scaled_alpha; C3[15] = res3_15 * scaled_alpha;

        temp = bk - off - 4;
        ptrba += temp * 16;
        ptrbb += temp * 4;
        C0 += 16;
        C1 += 16;
        C2 += 16;
        C3 += 16;
    }

    if (bm & 8) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0.0f;
        res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 = 0.0f;
        res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 = 0.0f;
        res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 = 0.0f;

        for (k = 0; k < off + 4; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            res0_0 += ptrba[0]*b0; res1_0 += ptrba[0]*b1; res2_0 += ptrba[0]*b2; res3_0 += ptrba[0]*b3;
            res0_1 += ptrba[1]*b0; res1_1 += ptrba[1]*b1; res2_1 += ptrba[1]*b2; res3_1 += ptrba[1]*b3;
            res0_2 += ptrba[2]*b0; res1_2 += ptrba[2]*b1; res2_2 += ptrba[2]*b2; res3_2 += ptrba[2]*b3;
            res0_3 += ptrba[3]*b0; res1_3 += ptrba[3]*b1; res2_3 += ptrba[3]*b2; res3_3 += ptrba[3]*b3;
            res0_4 += ptrba[4]*b0; res1_4 += ptrba[4]*b1; res2_4 += ptrba[4]*b2; res3_4 += ptrba[4]*b3;
            res0_5 += ptrba[5]*b0; res1_5 += ptrba[5]*b1; res2_5 += ptrba[5]*b2; res3_5 += ptrba[5]*b3;
            res0_6 += ptrba[6]*b0; res1_6 += ptrba[6]*b1; res2_6 += ptrba[6]*b2; res3_6 += ptrba[6]*b3;
            res0_7 += ptrba[7]*b0; res1_7 += ptrba[7]*b1; res2_7 += ptrba[7]*b2; res3_7 += ptrba[7]*b3;
            ptrba += 8;
            ptrbb += 4;
        }

        float sa = alpha;
        for (int idx = 0; idx < 8; ++idx) {
            C0[idx] = (&res0_0)[idx] * sa;
            C1[idx] = (&res1_0)[idx] * sa;
            C2[idx] = (&res2_0)[idx] * sa;
            C3[idx] = (&res3_0)[idx] * sa;
        }

        temp = bk - off - 4;
        ptrba += temp * 8;
        ptrbb += temp * 4;
        C0 += 8;
        C1 += 8;
        C2 += 8;
        C3 += 8;
    }

    if (bm & 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0.0f;
        res1_0 = res1_1 = res1_2 = res1_3 = 0.0f;
        res2_0 = res2_1 = res2_2 = res2_3 = 0.0f;
        res3_0 = res3_1 = res3_2 = res3_3 = 0.0f;

        for (k = 0; k < off + 4; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            res0_0 += ptrba[0]*b0; res1_0 += ptrba[0]*b1; res2_0 += ptrba[0]*b2; res3_0 += ptrba[0]*b3;
            res0_1 += ptrba[1]*b0; res1_1 += ptrba[1]*b1; res2_1 += ptrba[1]*b2; res3_1 += ptrba[1]*b3;
            res0_2 += ptrba[2]*b0; res1_2 += ptrba[2]*b1; res2_2 += ptrba[2]*b2; res3_2 += ptrba[2]*b3;
            res0_3 += ptrba[3]*b0; res1_3 += ptrba[3]*b1; res2_3 += ptrba[3]*b2; res3_3 += ptrba[3]*b3;
            ptrba += 4;
            ptrbb += 4;
        }

        float sa = alpha;
        C0[0] = res0_0 * sa; C0[1] = res0_1 * sa; C0[2] = res0_2 * sa; C0[3] = res0_3 * sa;
        C1[0] = res1_0 * sa; C1[1] = res1_1 * sa; C1[2] = res1_2 * sa; C1[3] = res1_3 * sa;
        C2[0] = res2_0 * sa; C2[1] = res2_1 * sa; C2[2] = res2_2 * sa; C2[3] = res2_3 * sa;
        C3[0] = res3_0 * sa; C3[1] = res3_1 * sa; C3[2] = res3_2 * sa; C3[3] = res3_3 * sa;

        temp = bk - off - 4;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4;
        C1 += 4;
        C2 += 4;
        C3 += 4;
    }

    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = res1_0 = res1_1 = res2_0 = res2_1 = res3_0 = res3_1 = 0.0f;
        for (k = 0; k < off + 4; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            res0_0 += ptrba[0]*b0; res1_0 += ptrba[0]*b1; res2_0 += ptrba[0]*b2; res3_0 += ptrba[0]*b3;
            res0_1 += ptrba[1]*b0; res1_1 += ptrba[1]*b1; res2_1 += ptrba[1]*b2; res3_1 += ptrba[1]*b3;
            ptrba += 2;
            ptrbb += 4;
        }

        float sa = alpha;
        C0[0] = res0_0 * sa; C0[1] = res0_1 * sa;
        C1[0] = res1_0 * sa; C1[1] = res1_1 * sa;
        C2[0] = res2_0 * sa; C2[1] = res2_1 * sa;
        C3[0] = res3_0 * sa; C3[1] = res3_1 * sa;

        temp = bk - off - 4;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2;
        C1 += 2;
        C2 += 2;
        C3 += 2;
    }

    if (bm & 1) {
        ptrbb = bb;
        res0_0 = res1_0 = res2_0 = res3_0 = 0.0f;
        for (k = 0; k < off + 4; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = ptrba[0];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            ptrba++;
            ptrbb += 4;
        }

        float sa = alpha;
        C0[0] = res0_0 * sa;
        C1[0] = res1_0 * sa;
        C2[0] = res2_0 * sa;
        C3[0] = res3_0 * sa;

        temp = bk - off - 4;
        ptrba += temp;
        ptrbb += temp * 4;
        C0++;
        C1++;
        C2++;
        C3++;
    }

    bb += bk * 4;
    C += ldc * 4;
}
}
