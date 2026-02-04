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
extern float *C4;
extern float *C5;
extern float *C6;
extern float *C7;
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
extern float res4_0;
extern float res4_1;
extern float res4_2;
extern float res4_3;
extern float res4_4;
extern float res4_5;
extern float res4_6;
extern float res4_7;
extern float res4_8;
extern float res4_9;
extern float res4_10;
extern float res4_11;
extern float res4_12;
extern float res4_13;
extern float res4_14;
extern float res4_15;
extern float res5_0;
extern float res5_1;
extern float res5_2;
extern float res5_3;
extern float res5_4;
extern float res5_5;
extern float res5_6;
extern float res5_7;
extern float res5_8;
extern float res5_9;
extern float res5_10;
extern float res5_11;
extern float res5_12;
extern float res5_13;
extern float res5_14;
extern float res5_15;
extern float res6_0;
extern float res6_1;
extern float res6_2;
extern float res6_3;
extern float res6_4;
extern float res6_5;
extern float res6_6;
extern float res6_7;
extern float res6_8;
extern float res6_9;
extern float res6_10;
extern float res6_11;
extern float res6_12;
extern float res6_13;
extern float res6_14;
extern float res6_15;
extern float res7_0;
extern float res7_1;
extern float res7_2;
extern float res7_3;
extern float res7_4;
extern float res7_5;
extern float res7_6;
extern float res7_7;
extern float res7_8;
extern float res7_9;
extern float res7_10;
extern float res7_11;
extern float res7_12;
extern float res7_13;
extern float res7_14;
extern float res7_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern float b4;
extern float b5;
extern float b6;
extern float b7;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < bn / 8; j += 1) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C0 + 2 * ldc;
    C3 = C0 + 3 * ldc;
    C4 = C0 + 4 * ldc;
    C5 = C0 + 5 * ldc;
    C6 = C0 + 6 * ldc;
    C7 = C0 + 7 * ldc;
    ptrba = ba;
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 =
        res0_8 = res0_9 = res0_10 = res0_11 = res0_12 = res0_13 = res0_14 = res0_15 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 =
        res1_8 = res1_9 = res1_10 = res1_11 = res1_12 = res1_13 = res1_14 = res1_15 = 0;
        res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 =
        res2_8 = res2_9 = res2_10 = res2_11 = res2_12 = res2_13 = res2_14 = res2_15 = 0;
        res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 =
        res3_8 = res3_9 = res3_10 = res3_11 = res3_12 = res3_13 = res3_14 = res3_15 = 0;
        res4_0 = res4_1 = res4_2 = res4_3 = res4_4 = res4_5 = res4_6 = res4_7 =
        res4_8 = res4_9 = res4_10 = res4_11 = res4_12 = res4_13 = res4_14 = res4_15 = 0;
        res5_0 = res5_1 = res5_2 = res5_3 = res5_4 = res5_5 = res5_6 = res5_7 =
        res5_8 = res5_9 = res5_10 = res5_11 = res5_12 = res5_13 = res5_14 = res5_15 = 0;
        res6_0 = res6_1 = res6_2 = res6_3 = res6_4 = res6_5 = res6_6 = res6_7 =
        res6_8 = res6_9 = res6_10 = res6_11 = res6_12 = res6_13 = res6_14 = res6_15 = 0;
        res7_0 = res7_1 = res7_2 = res7_3 = res7_4 = res7_5 = res7_6 = res7_7 =
        res7_8 = res7_9 = res7_10 = res7_11 = res7_12 = res7_13 = res7_14 = res7_15 = 0;
        temp = off + 8;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0]; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            b4 = ptrbb[4]; b5 = ptrbb[5]; b6 = ptrbb[6]; b7 = ptrbb[7];
            a0 = ptrba[0]; a1 = ptrba[1];
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            res4_0 += a0 * b4; res5_0 += a0 * b5; res6_0 += a0 * b6; res7_0 += a0 * b7;
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
            res4_1 += a1 * b4; res5_1 += a1 * b5; res6_1 += a1 * b6; res7_1 += a1 * b7;

            a0 = ptrba[2]; a1 = ptrba[3];
            res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
            res4_2 += a0 * b4; res5_2 += a0 * b5; res6_2 += a0 * b6; res7_2 += a0 * b7;
            res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;
            res4_3 += a1 * b4; res5_3 += a1 * b5; res6_3 += a1 * b6; res7_3 += a1 * b7;

            a0 = ptrba[4]; a1 = ptrba[5];
            res0_4 += a0 * b0; res1_4 += a0 * b1; res2_4 += a0 * b2; res3_4 += a0 * b3;
            res4_4 += a0 * b4; res5_4 += a0 * b5; res6_4 += a0 * b6; res7_4 += a0 * b7;
            res0_5 += a1 * b0; res1_5 += a1 * b1; res2_5 += a1 * b2; res3_5 += a1 * b3;
            res4_5 += a1 * b4; res5_5 += a1 * b5; res6_5 += a1 * b6; res7_5 += a1 * b7;

            a0 = ptrba[6]; a1 = ptrba[7];
            res0_6 += a0 * b0; res1_6 += a0 * b1; res2_6 += a0 * b2; res3_6 += a0 * b3;
            res4_6 += a0 * b4; res5_6 += a0 * b5; res6_6 += a0 * b6; res7_6 += a0 * b7;
            res0_7 += a1 * b0; res1_7 += a1 * b1; res2_7 += a1 * b2; res3_7 += a1 * b3;
            res4_7 += a1 * b4; res5_7 += a1 * b5; res6_7 += a1 * b6; res7_7 += a1 * b7;

            a0 = ptrba[8]; a1 = ptrba[9];
            res0_8 += a0 * b0; res1_8 += a0 * b1; res2_8 += a0 * b2; res3_8 += a0 * b3;
            res4_8 += a0 * b4; res5_8 += a0 * b5; res6_8 += a0 * b6; res7_8 += a0 * b7;
            res0_9 += a1 * b0; res1_9 += a1 * b1; res2_9 += a1 * b2; res3_9 += a1 * b3;
            res4_9 += a1 * b4; res5_9 += a1 * b5; res6_9 += a1 * b6; res7_9 += a1 * b7;

            a0 = ptrba[10]; a1 = ptrba[11];
            res0_10 += a0 * b0; res1_10 += a0 * b1; res2_10 += a0 * b2; res3_10 += a0 * b3;
            res4_10 += a0 * b4; res5_10 += a0 * b5; res6_10 += a0 * b6; res7_10 += a0 * b7;
            res0_11 += a1 * b0; res1_11 += a1 * b1; res2_11 += a1 * b2; res3_11 += a1 * b3;
            res4_11 += a1 * b4; res5_11 += a1 * b5; res6_11 += a1 * b6; res7_11 += a1 * b7;

            a0 = ptrba[12]; a1 = ptrba[13];
            res0_12 += a0 * b0; res1_12 += a0 * b1; res2_12 += a0 * b2; res3_12 += a0 * b3;
            res4_12 += a0 * b4; res5_12 += a0 * b5; res6_12 += a0 * b6; res7_12 += a0 * b7;
            res0_13 += a1 * b0; res1_13 += a1 * b1; res2_13 += a1 * b2; res3_13 += a1 * b3;
            res4_13 += a1 * b4; res5_13 += a1 * b5; res6_13 += a1 * b6; res7_13 += a1 * b7;

            a0 = ptrba[14]; a1 = ptrba[15];
            res0_14 += a0 * b0; res1_14 += a0 * b1; res2_14 += a0 * b2; res3_14 += a0 * b3;
            res4_14 += a0 * b4; res5_14 += a0 * b5; res6_14 += a0 * b6; res7_14 += a0 * b7;
            res0_15 += a1 * b0; res1_15 += a1 * b1; res2_15 += a1 * b2; res3_15 += a1 * b3;
            res4_15 += a1 * b4; res5_15 += a1 * b5; res6_15 += a1 * b6; res7_15 += a1 * b7;

            ptrba += 16;
            ptrbb += 8;
        }
        float alphaf = alpha;
        res0_0 *= alphaf; res0_1 *= alphaf; res0_2 *= alphaf; res0_3 *= alphaf;
        res0_4 *= alphaf; res0_5 *= alphaf; res0_6 *= alphaf; res0_7 *= alphaf;
        res0_8 *= alphaf; res0_9 *= alphaf; res0_10 *= alphaf; res0_11 *= alphaf;
        res0_12 *= alphaf; res0_13 *= alphaf; res0_14 *= alphaf; res0_15 *= alphaf;
        res1_0 *= alphaf; res1_1 *= alphaf; res1_2 *= alphaf; res1_3 *= alphaf;
        res1_4 *= alphaf; res1_5 *= alphaf; res1_6 *= alphaf; res1_7 *= alphaf;
        res1_8 *= alphaf; res1_9 *= alphaf; res1_10 *= alphaf; res1_11 *= alphaf;
        res1_12 *= alphaf; res1_13 *= alphaf; res1_14 *= alphaf; res1_15 *= alphaf;
        res2_0 *= alphaf; res2_1 *= alphaf; res2_2 *= alphaf; res2_3 *= alphaf;
        res2_4 *= alphaf; res2_5 *= alphaf; res2_6 *= alphaf; res2_7 *= alphaf;
        res2_8 *= alphaf; res2_9 *= alphaf; res2_10 *= alphaf; res2_11 *= alphaf;
        res2_12 *= alphaf; res2_13 *= alphaf; res2_14 *= alphaf; res2_15 *= alphaf;
        res3_0 *= alphaf; res3_1 *= alphaf; res3_2 *= alphaf; res3_3 *= alphaf;
        res3_4 *= alphaf; res3_5 *= alphaf; res3_6 *= alphaf; res3_7 *= alphaf;
        res3_8 *= alphaf; res3_9 *= alphaf; res3_10 *= alphaf; res3_11 *= alphaf;
        res3_12 *= alphaf; res3_13 *= alphaf; res3_14 *= alphaf; res3_15 *= alphaf;
        res4_0 *= alphaf; res4_1 *= alphaf; res4_2 *= alphaf; res4_3 *= alphaf;
        res4_4 *= alphaf; res4_5 *= alphaf; res4_6 *= alphaf; res4_7 *= alphaf;
        res4_8 *= alphaf; res4_9 *= alphaf; res4_10 *= alphaf; res4_11 *= alphaf;
        res4_12 *= alphaf; res4_13 *= alphaf; res4_14 *= alphaf; res4_15 *= alphaf;
        res5_0 *= alphaf; res5_1 *= alphaf; res5_2 *= alphaf; res5_3 *= alphaf;
        res5_4 *= alphaf; res5_5 *= alphaf; res5_6 *= alphaf; res5_7 *= alphaf;
        res5_8 *= alphaf; res5_9 *= alphaf; res5_10 *= alphaf; res5_11 *= alphaf;
        res5_12 *= alphaf; res5_13 *= alphaf; res5_14 *= alphaf; res5_15 *= alphaf;
        res6_0 *= alphaf; res6_1 *= alphaf; res6_2 *= alphaf; res6_3 *= alphaf;
        res6_4 *= alphaf; res6_5 *= alphaf; res6_6 *= alphaf; res6_7 *= alphaf;
        res6_8 *= alphaf; res6_9 *= alphaf; res6_10 *= alphaf; res6_11 *= alphaf;
        res6_12 *= alphaf; res6_13 *= alphaf; res6_14 *= alphaf; res6_15 *= alphaf;
        res7_0 *= alphaf; res7_1 *= alphaf; res7_2 *= alphaf; res7_3 *= alphaf;
        res7_4 *= alphaf; res7_5 *= alphaf; res7_6 *= alphaf; res7_7 *= alphaf;
        res7_8 *= alphaf; res7_9 *= alphaf; res7_10 *= alphaf; res7_11 *= alphaf;
        res7_12 *= alphaf; res7_13 *= alphaf; res7_14 *= alphaf; res7_15 *= alphaf;

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
        C4[0] = res4_0; C4[1] = res4_1; C4[2] = res4_2; C4[3] = res4_3;
        C4[4] = res4_4; C4[5] = res4_5; C4[6] = res4_6; C4[7] = res4_7;
        C4[8] = res4_8; C4[9] = res4_9; C4[10] = res4_10; C4[11] = res4_11;
        C4[12] = res4_12; C4[13] = res4_13; C4[14] = res4_14; C4[15] = res4_15;
        C5[0] = res5_0; C5[1] = res5_1; C5[2] = res5_2; C5[3] = res5_3;
        C5[4] = res5_4; C5[5] = res5_5; C5[6] = res5_6; C5[7] = res5_7;
        C5[8] = res5_8; C5[9] = res5_9; C5[10] = res5_10; C5[11] = res5_11;
        C5[12] = res5_12; C5[13] = res5_13; C5[14] = res5_14; C5[15] = res5_15;
        C6[0] = res6_0; C6[1] = res6_1; C6[2] = res6_2; C6[3] = res6_3;
        C6[4] = res6_4; C6[5] = res6_5; C6[6] = res6_6; C6[7] = res6_7;
        C6[8] = res6_8; C6[9] = res6_9; C6[10] = res6_10; C6[11] = res6_11;
        C6[12] = res6_12; C6[13] = res6_13; C6[14] = res6_14; C6[15] = res6_15;
        C7[0] = res7_0; C7[1] = res7_1; C7[2] = res7_2; C7[3] = res7_3;
        C7[4] = res7_4; C7[5] = res7_5; C7[6] = res7_6; C7[7] = res7_7;
        C7[8] = res7_8; C7[9] = res7_9; C7[10] = res7_10; C7[11] = res7_11;
        C7[12] = res7_12; C7[13] = res7_13; C7[14] = res7_14; C7[15] = res7_15;

        temp = bk - off - 8;
        ptrba += temp * 16;
        ptrbb += temp * 8;
        C0 += 16; C1 += 16; C2 += 16; C3 += 16;
        C4 += 16; C5 += 16; C6 += 16; C7 += 16;
    }

    if (bm & 15) {
        int rem = bm & 15;
        ptrbb = bb;
        for (int r = 0; r < 8; r++) {
            float *Cr = &C[r * ldc];
            for (int c = 0; c < rem; c++) {
                float sum = 0.0f;
                float *pa = ptrba + c;
                float *pb = ptrbb;
                temp = off + 8;
                for (k = 0; k < temp; k++) {
                    sum += pa[k * 16] * pb[r];
                    pb += 8;
                }
                Cr[c] = sum * alpha;
            }
        }
        temp = bk - off - 8;
        ptrba += temp * 16 + ((rem < 8 ? 8 : rem) - 8);
        ptrbb += temp * 8;
        C0 = C + rem;
        C1 = C0 + ldc; C2 = C1 + ldc; C3 = C2 + ldc;
        C4 = C3 + ldc; C5 = C4 + ldc; C6 = C5 + ldc; C7 = C6 + ldc;
    } else {
        C0 = C + 16 * (bm / 16);
        C1 = C0 + ldc; C2 = C1 + ldc; C3 = C2 + ldc;
        C4 = C3 + ldc; C5 = C4 + ldc; C6 = C5 + ldc; C7 = C6 + ldc;
    }

    k = (bk << 3);
    bb += k;
    C += (ldc << 3);
}
}
