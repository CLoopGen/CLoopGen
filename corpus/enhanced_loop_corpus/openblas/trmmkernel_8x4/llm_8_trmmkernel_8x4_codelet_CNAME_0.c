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
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        res1_0 = 0;
        res1_1 = 0;
        res1_2 = 0;
        res1_3 = 0;
        res1_4 = 0;
        res1_5 = 0;
        res1_6 = 0;
        res1_7 = 0;
        res2_0 = 0;
        res2_1 = 0;
        res2_2 = 0;
        res2_3 = 0;
        res2_4 = 0;
        res2_5 = 0;
        res2_6 = 0;
        res2_7 = 0;
        res3_0 = 0;
        res3_1 = 0;
        res3_2 = 0;
        res3_3 = 0;
        res3_4 = 0;
        res3_5 = 0;
        res3_6 = 0;
        res3_7 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            b2 = ptrbb[2];
            b3 = ptrbb[3];
            a0 = ptrba[0];
            a1 = ptrba[1];
            float a0b0 = a0 * b0, a0b1 = a0 * b1, a0b2 = a0 * b2, a0b3 = a0 * b3;
            float a1b0 = a1 * b0, a1b1 = a1 * b1, a1b2 = a1 * b2, a1b3 = a1 * b3;
            res0_0 += a0b0; res1_0 += a0b1; res2_0 += a0b2; res3_0 += a0b3;
            res0_1 += a1b0; res1_1 += a1b1; res2_1 += a1b2; res3_1 += a1b3;

            a0 = ptrba[2]; a1 = ptrba[3];
            a0b0 = a0 * b0; a0b1 = a0 * b1; a0b2 = a0 * b2; a0b3 = a0 * b3;
            a1b0 = a1 * b0; a1b1 = a1 * b1; a1b2 = a1 * b2; a1b3 = a1 * b3;
            res0_2 += a0b0; res1_2 += a0b1; res2_2 += a0b2; res3_2 += a0b3;
            res0_3 += a1b0; res1_3 += a1b1; res2_3 += a1b2; res3_3 += a1b3;

            a0 = ptrba[4]; a1 = ptrba[5];
            a0b0 = a0 * b0; a0b1 = a0 * b1; a0b2 = a0 * b2; a0b3 = a0 * b3;
            a1b0 = a1 * b0; a1b1 = a1 * b1; a1b2 = a1 * b2; a1b3 = a1 * b3;
            res0_4 += a0b0; res1_4 += a0b1; res2_4 += a0b2; res3_4 += a0b3;
            res0_5 += a1b0; res1_5 += a1b1; res2_5 += a1b2; res3_5 += a1b3;

            a0 = ptrba[6]; a1 = ptrba[7];
            a0b0 = a0 * b0; a0b1 = a0 * b1; a0b2 = a0 * b2; a0b3 = a0 * b3;
            a1b0 = a1 * b0; a1b1 = a1 * b1; a1b2 = a1 * b2; a1b3 = a1 * b3;
            res0_6 += a0b0; res1_6 += a0b1; res2_6 += a0b2; res3_6 += a0b3;
            res0_7 += a1b0; res1_7 += a1b1; res2_7 += a1b2; res3_7 += a1b3;

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

        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
        C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
        C1[4] = res1_4; C1[5] = res1_5; C1[6] = res1_6; C1[7] = res1_7;
        C2[0] = res2_0; C2[1] = res2_1; C2[2] = res2_2; C2[3] = res2_3;
        C2[4] = res2_4; C2[5] = res2_5; C2[6] = res2_6; C2[7] = res2_7;
        C3[0] = res3_0; C3[1] = res3_1; C3[2] = res3_2; C3[3] = res3_3;
        C3[4] = res3_4; C3[5] = res3_5; C3[6] = res3_6; C3[7] = res3_7;

        temp = bk - off - 4;
        ptrba += temp * 8;
        ptrbb += temp * 4;
        C0 += 8; C1 += 8; C2 += 8; C3 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = 0;
        res2_0 = res2_1 = res2_2 = res2_3 = 0;
        res3_0 = res3_1 = res3_2 = res3_3 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = ptrba[0]; a1 = ptrba[1];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;

            a0 = ptrba[2]; a1 = ptrba[3];
            res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
            res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;

            ptrba += 4;
            ptrbb += 4;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha; res2_2 *= alpha; res2_3 *= alpha;
        res3_0 *= alpha; res3_1 *= alpha; res3_2 *= alpha; res3_3 *= alpha;

        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
        C2[0] = res2_0; C2[1] = res2_1; C2[2] = res2_2; C2[3] = res2_3;
        C3[0] = res3_0; C3[1] = res3_1; C3[2] = res3_2; C3[3] = res3_3;

        temp = bk - off - 4;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = 0; res1_0 = res1_1 = 0;
        res2_0 = res2_1 = 0; res3_0 = res3_1 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = ptrba[0]; a1 = ptrba[1];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
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
        res0_0 = 0; res1_0 = 0; res2_0 = 0; res3_0 = 0;
        temp = off + 4;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = ptrba[0];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            ptrba++;
            ptrbb += 4;
        }
        res0_0 *= alpha; res1_0 *= alpha; res2_0 *= alpha; res3_0 *= alpha;
        C0[0] = res0_0; C1[0] = res1_0; C2[0] = res2_0; C3[0] = res3_0;
        temp = bk - off - 4;
        ptrba += temp;
        ptrbb += temp * 4;
        C0++; C1++; C2++; C3++;
    }
    bb += (bk << 2);
    C += (ldc << 2);
}
}
