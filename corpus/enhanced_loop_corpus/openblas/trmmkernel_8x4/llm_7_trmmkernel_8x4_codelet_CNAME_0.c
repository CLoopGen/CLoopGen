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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
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
    C2 = C1 + ldc;
    C3 = C2 + ldc;
    ptrba = ba;
    for (i = 0; i < bm / 8; i += 1) {
        ptrbb = bb;
        res0_0 = 0; res0_1 = 0; res0_2 = 0; res0_3 = 0;
        res0_4 = 0; res0_5 = 0; res0_6 = 0; res0_7 = 0;
        res1_0 = 0; res1_1 = 0; res1_2 = 0; res1_3 = 0;
        res1_4 = 0; res1_5 = 0; res1_6 = 0; res1_7 = 0;
        res2_0 = 0; res2_1 = 0; res2_2 = 0; res2_3 = 0;
        res2_4 = 0; res2_5 = 0; res2_6 = 0; res2_7 = 0;
        res3_0 = 0; res3_1 = 0; res3_2 = 0; res3_3 = 0;
        res3_4 = 0; res3_5 = 0; res3_6 = 0; res3_7 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            float b_vals[4];
            b_vals[0] = ptrbb[0]; b_vals[1] = ptrbb[1];
            b_vals[2] = ptrbb[2]; b_vals[3] = ptrbb[3];

            res0_0 += ptrba[0] * b_vals[0];
            res1_0 += ptrba[0] * b_vals[1];
            res2_0 += ptrba[0] * b_vals[2];
            res3_0 += ptrba[0] * b_vals[3];

            res0_1 += ptrba[1] * b_vals[0];
            res1_1 += ptrba[1] * b_vals[1];
            res2_1 += ptrba[1] * b_vals[2];
            res3_1 += ptrba[1] * b_vals[3];

            res0_2 += ptrba[2] * b_vals[0];
            res1_2 += ptrba[2] * b_vals[1];
            res2_2 += ptrba[2] * b_vals[2];
            res3_2 += ptrba[2] * b_vals[3];

            res0_3 += ptrba[3] * b_vals[0];
            res1_3 += ptrba[3] * b_vals[1];
            res2_3 += ptrba[3] * b_vals[2];
            res3_3 += ptrba[3] * b_vals[3];

            res0_4 += ptrba[4] * b_vals[0];
            res1_4 += ptrba[4] * b_vals[1];
            res2_4 += ptrba[4] * b_vals[2];
            res3_4 += ptrba[4] * b_vals[3];

            res0_5 += ptrba[5] * b_vals[0];
            res1_5 += ptrba[5] * b_vals[1];
            res2_5 += ptrba[5] * b_vals[2];
            res3_5 += ptrba[5] * b_vals[3];

            res0_6 += ptrba[6] * b_vals[0];
            res1_6 += ptrba[6] * b_vals[1];
            res2_6 += ptrba[6] * b_vals[2];
            res3_6 += ptrba[6] * b_vals[3];

            res0_7 += ptrba[7] * b_vals[0];
            res1_7 += ptrba[7] * b_vals[1];
            res2_7 += ptrba[7] * b_vals[2];
            res3_7 += ptrba[7] * b_vals[3];

            ptrba += 8;
            ptrbb += 4;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        res1_4 *= alpha; res1_5 *= alpha; res1_6 *= alpha; res1_7 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha; res2_2 *= alpha; res2_3 *= alpha;
        res2_4 *= alpha; res2_5 *= alpha; res2_6 *= alpha; res2_7 *= alpha;
        res3_0 *= alpha; res3_1 *= alpha; res3_2 *= alpha; res3_3 *= alpha;
        res3_4 *= alpha; res3_5 *= alpha; res3_6 *= alpha; res3_7 *= alpha;

        for (int m = 0; m < 8; ++m) {
            C0[m] = *((float*)&res0_0 + m);
            C1[m] = *((float*)&res1_0 + m);
            C2[m] = *((float*)&res2_0 + m);
            C3[m] = *((float*)&res3_0 + m);
        }

        temp = bk - off - 4;
        ptrba += temp * 8;
        ptrbb += temp * 4;
        C0 += 8; C1 += 8; C2 += 8; C3 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = 0; res0_1 = 0; res0_2 = 0; res0_3 = 0;
        res1_0 = 0; res1_1 = 0; res1_2 = 0; res1_3 = 0;
        res2_0 = 0; res2_1 = 0; res2_2 = 0; res2_3 = 0;
        res3_0 = 0; res3_1 = 0; res3_2 = 0; res3_3 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            float b_vals[4] = {ptrbb[0], ptrbb[1], ptrbb[2], ptrbb[3]};
            res0_0 += ptrba[0] * b_vals[0]; res1_0 += ptrba[0] * b_vals[1];
            res2_0 += ptrba[0] * b_vals[2]; res3_0 += ptrba[0] * b_vals[3];
            res0_1 += ptrba[1] * b_vals[0]; res1_1 += ptrba[1] * b_vals[1];
            res2_1 += ptrba[1] * b_vals[2]; res3_1 += ptrba[1] * b_vals[3];
            res0_2 += ptrba[2] * b_vals[0]; res1_2 += ptrba[2] * b_vals[1];
            res2_2 += ptrba[2] * b_vals[2]; res3_2 += ptrba[2] * b_vals[3];
            res0_3 += ptrba[3] * b_vals[0]; res1_3 += ptrba[3] * b_vals[1];
            res2_3 += ptrba[3] * b_vals[2]; res3_3 += ptrba[3] * b_vals[3];

            ptrba += 4;
            ptrbb += 4;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha; res2_2 *= alpha; res2_3 *= alpha;
        res3_0 *= alpha; res3_1 *= alpha; res3_2 *= alpha; res3_3 *= alpha;

        for (int m = 0; m < 4; ++m) {
            C0[m] = *((float*)&res0_0 + m);
            C1[m] = *((float*)&res1_0 + m);
            C2[m] = *((float*)&res2_0 + m);
            C3[m] = *((float*)&res3_0 + m);
        }

        temp = bk - off - 4;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0; res0_1 = 0;
        res1_0 = 0; res1_1 = 0;
        res2_0 = 0; res2_1 = 0;
        res3_0 = 0; res3_1 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            float b0 = ptrbb[0], b1 = ptrbb[1], b2 = ptrbb[2], b3 = ptrbb[3];
            res0_0 += ptrba[0] * b0; res1_0 += ptrba[0] * b1;
            res2_0 += ptrba[0] * b2; res3_0 += ptrba[0] * b3;
            res0_1 += ptrba[1] * b0; res1_1 += ptrba[1] * b1;
            res2_1 += ptrba[1] * b2; res3_1 += ptrba[1] * b3;

            ptrba += 2;
            ptrbb += 4;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha;
        res3_0 *= alpha; res3_1 *= alpha;

        C0[0] = res0_0; C0[1] = res0_1;
        C1[0] = res1_0; C1[1] = res1_1;
        C2[0] = res2_0; C2[1] = res2_1;
        C3[0] = res3_0; C3[1] = res3_1;

        temp = bk - off - 4;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2; C1 += 2; C2 += 2; C3 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = res1_0 = res2_0 = res3_0 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            float b0 = ptrbb[0], b1 = ptrbb[1], b2 = ptrbb[2], b3 = ptrbb[3];
            float a0 = ptrba[0];
            res0_0 += a0 * b0; res1_0 += a0 * b1;
            res2_0 += a0 * b2; res3_0 += a0 * b3;

            ptrba++;
            ptrbb += 4;
        }
        res0_0 *= alpha; res1_0 *= alpha;
        res2_0 *= alpha; res3_0 *= alpha;

        C0[0] = res0_0;
        C1[0] = res1_0;
        C2[0] = res2_0;
        C3[0] = res3_0;

        temp = bk - off - 4;
        ptrba += temp;
        ptrbb += temp * 4;
        C0++; C1++; C2++; C3++;
    }
    bb += (bk << 2);
    C += (ldc << 2);
}
}
