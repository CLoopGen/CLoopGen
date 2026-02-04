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
        res0_0 = 0; res0_1 = 0; res0_2 = 0; res0_3 = 0;
        res0_4 = 0; res0_5 = 0; res0_6 = 0; res0_7 = 0;
        res0_8 = 0; res0_9 = 0; res0_10 = 0; res0_11 = 0;
        res0_12 = 0; res0_13 = 0; res0_14 = 0; res0_15 = 0;
        res1_0 = 0; res1_1 = 0; res1_2 = 0; res1_3 = 0;
        res1_4 = 0; res1_5 = 0; res1_6 = 0; res1_7 = 0;
        res1_8 = 0; res1_9 = 0; res1_10 = 0; res1_11 = 0;
        res1_12 = 0; res1_13 = 0; res1_14 = 0; res1_15 = 0;
        res2_0 = 0; res2_1 = 0; res2_2 = 0; res2_3 = 0;
        res2_4 = 0; res2_5 = 0; res2_6 = 0; res2_7 = 0;
        res2_8 = 0; res2_9 = 0; res2_10 = 0; res2_11 = 0;
        res2_12 = 0; res2_13 = 0; res2_14 = 0; res2_15 = 0;
        res3_0 = 0; res3_1 = 0; res3_2 = 0; res3_3 = 0;
        res3_4 = 0; res3_5 = 0; res3_6 = 0; res3_7 = 0;
        res3_8 = 0; res3_9 = 0; res3_10 = 0; res3_11 = 0;
        res3_12 = 0; res3_13 = 0; res3_14 = 0; res3_15 = 0;

        for (k = 0; k < off + 4; k++) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = *ptrba; a1 = ptrba[1];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;

            a0 = ptrba[2]; a1 = ptrba[3];
            res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
            res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;

            a0 = ptrba[4]; a1 = ptrba[5];
            res0_4 += a0 * b0; res1_4 += a0 * b1; res2_4 += a0 * b2; res3_4 += a0 * b3;
            res0_5 += a1 * b0; res1_5 += a1 * b1; res2_5 += a1 * b2; res3_5 += a1 * b3;

            a0 = ptrba[6]; a1 = ptrba[7];
            res0_6 += a0 * b0; res1_6 += a0 * b1; res2_6 += a0 * b2; res3_6 += a0 * b3;
            res0_7 += a1 * b0; res1_7 += a1 * b1; res2_7 += a1 * b2; res3_7 += a1 * b3;

            a0 = ptrba[8]; a1 = ptrba[9];
            res0_8 += a0 * b0; res1_8 += a0 * b1; res2_8 += a0 * b2; res3_8 += a0 * b3;
            res0_9 += a1 * b0; res1_9 += a1 * b1; res2_9 += a1 * b2; res3_9 += a1 * b3;

            a0 = ptrba[10]; a1 = ptrba[11];
            res0_10 += a0 * b0; res1_10 += a0 * b1; res2_10 += a0 * b2; res3_10 += a0 * b3;
            res0_11 += a1 * b0; res1_11 += a1 * b1; res2_11 += a1 * b2; res3_11 += a1 * b3;

            a0 = ptrba[12]; a1 = ptrba[13];
            res0_12 += a0 * b0; res1_12 += a0 * b1; res2_12 += a0 * b2; res3_12 += a0 * b3;
            res0_13 += a1 * b0; res1_13 += a1 * b1; res2_13 += a1 * b2; res3_13 += a1 * b3;

            a0 = ptrba[14]; a1 = ptrba[15];
            res0_14 += a0 * b0; res1_14 += a0 * b1; res2_14 += a0 * b2; res3_14 += a0 * b3;
            res0_15 += a1 * b0; res1_15 += a1 * b1; res2_15 += a1 * b2; res3_15 += a1 * b3;

            ptrba += 16;
            ptrbb += 4;
        }

        for (int r = 0; r < 16; r++) {
            float scaled_val = alpha;
            ((float*)(&res0_0))[r] *= scaled_val;
            ((float*)(&res1_0))[r] *= scaled_val;
            ((float*)(&res2_0))[r] *= scaled_val;
            ((float*)(&res3_0))[r] *= scaled_val;
        }

        for (int c = 0; c < 16; c++) {
            C0[c] = ((float*)(&res0_0))[c];
            C1[c] = ((float*)(&res1_0))[c];
            C2[c] = ((float*)(&res2_0))[c];
            C3[c] = ((float*)(&res3_0))[c];
        }

        temp = bk - off - 4;
        ptrba += temp * 16;
        ptrbb += temp * 4;
        C0 += 16; C1 += 16; C2 += 16; C3 += 16;
    }
    if (bm & 8) {
        ptrbb = bb;
        for (int r = 0; r < 8; r++) {
            ((float*)(&res0_0))[r] = 0;
            ((float*)(&res1_0))[r] = 0;
            ((float*)(&res2_0))[r] = 0;
            ((float*)(&res3_0))[r] = 0;
        }
        for (k = 0; k < off + 4; k++) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            for (int idx = 0; idx < 8; idx++) {
                a0 = ptrba[idx];
                ((float*)(&res0_0))[idx] += a0 * b0;
                ((float*)(&res1_0))[idx] += a0 * b1;
                ((float*)(&res2_0))[idx] += a0 * b2;
                ((float*)(&res3_0))[idx] += a0 * b3;
            }
            ptrba += 8;
            ptrbb += 4;
        }
        for (int r = 0; r < 8; r++) {
            ((float*)(&res0_0))[r] *= alpha;
            ((float*)(&res1_0))[r] *= alpha;
            ((float*)(&res2_0))[r] *= alpha;
            ((float*)(&res3_0))[r] *= alpha;
        }
        for (int c = 0; c < 8; c++) {
            C0[c] = ((float*)(&res0_0))[c];
            C1[c] = ((float*)(&res1_0))[c];
            C2[c] = ((float*)(&res2_0))[c];
            C3[c] = ((float*)(&res3_0))[c];
        }
        temp = bk - off - 4;
        ptrba += temp * 8;
        ptrbb += temp * 4;
        C0 += 8; C1 += 8; C2 += 8; C3 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        for (int r = 0; r < 4; r++) {
            ((float*)(&res0_0))[r] = 0;
            ((float*)(&res1_0))[r] = 0;
            ((float*)(&res2_0))[r] = 0;
            ((float*)(&res3_0))[r] = 0;
        }
        for (k = 0; k < off + 4; k++) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            for (int idx = 0; idx < 4; idx++) {
                a0 = ptrba[idx];
                ((float*)(&res0_0))[idx] += a0 * b0;
                ((float*)(&res1_0))[idx] += a0 * b1;
                ((float*)(&res2_0))[idx] += a0 * b2;
                ((float*)(&res3_0))[idx] += a0 * b3;
            }
            ptrba += 4;
            ptrbb += 4;
        }
        for (int r = 0; r < 4; r++) {
            ((float*)(&res0_0))[r] *= alpha;
            ((float*)(&res1_0))[r] *= alpha;
            ((float*)(&res2_0))[r] *= alpha;
            ((float*)(&res3_0))[r] *= alpha;
        }
        for (int c = 0; c < 4; c++) {
            C0[c] = ((float*)(&res0_0))[c];
            C1[c] = ((float*)(&res1_0))[c];
            C2[c] = ((float*)(&res2_0))[c];
            C3[c] = ((float*)(&res3_0))[c];
        }
        temp = bk - off - 4;
        ptrba += temp * 4;
        ptrbb += temp * 4;
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = res1_0 = res1_1 = 0;
        res2_0 = res2_1 = res3_0 = res3_1 = 0;
        for (k = 0; k < off + 4; k++) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
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
        res0_0 = res1_0 = res2_0 = res3_0 = 0;
        for (k = 0; k < off + 4; k++) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = *ptrba;
            res0_0 += a0 * b0; res1_0 += a0 * b1;
            res2_0 += a0 * b2; res3_0 += a0 * b3;
            ptrba++;
            ptrbb += 4;
        }
        res0_0 *= alpha; res1_0 *= alpha;
        res2_0 *= alpha; res3_0 *= alpha;
        C0[0] = res0_0; C1[0] = res1_0;
        C2[0] = res2_0; C3[0] = res3_0;
        temp = bk - off - 4;
        ptrba += temp;
        ptrbb += temp * 4;
        C0++; C1++; C2++; C3++;
    }
    bb += (bk << 2);
    C += (ldc << 2);
}
}
