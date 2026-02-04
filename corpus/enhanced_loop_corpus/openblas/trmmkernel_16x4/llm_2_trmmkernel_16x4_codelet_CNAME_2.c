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
    for (i = 0; i < bm / 16; ++i) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 =
        res0_8 = res0_9 = res0_10 = res0_11 = res0_12 = res0_13 = res0_14 = res0_15 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 =
        res1_8 = res1_9 = res1_10 = res1_11 = res1_12 = res1_13 = res1_14 = res1_15 = 0;

        temp = off + 2;
        for (k = 0; k < temp; ++k) {
            b0 = *ptrbb;
            b1 = *(ptrbb + 1);
            for (BLASLONG vec_idx = 0; vec_idx < 16; vec_idx += 2) {
                a0 = ptrba[vec_idx];
                a1 = ptrba[vec_idx + 1];
                res0_0 += a0 * b0; res1_0 += a0 * b1;
                res0_1 += a1 * b0; res1_1 += a1 * b1;

                if (vec_idx + 2 < 16) {
                    a0 = ptrba[vec_idx + 2];
                    a1 = ptrba[vec_idx + 3];
                    res0_2 += a0 * b0; res1_2 += a0 * b1;
                    res0_3 += a1 * b0; res1_3 += a1 * b1;
                }
                if (vec_idx + 4 < 16) {
                    a0 = ptrba[vec_idx + 4];
                    a1 = ptrba[vec_idx + 5];
                    res0_4 += a0 * b0; res1_4 += a0 * b1;
                    res0_5 += a1 * b0; res1_5 += a1 * b1;
                }
                if (vec_idx + 6 < 16) {
                    a0 = ptrba[vec_idx + 6];
                    a1 = ptrba[vec_idx + 7];
                    res0_6 += a0 * b0; res1_6 += a0 * b1;
                    res0_7 += a1 * b0; res1_7 += a1 * b1;
                }
                if (vec_idx + 8 < 16) {
                    a0 = ptrba[vec_idx + 8];
                    a1 = ptrba[vec_idx + 9];
                    res0_8 += a0 * b0; res1_8 += a0 * b1;
                    res0_9 += a1 * b0; res1_9 += a1 * b1;
                }
                if (vec_idx + 10 < 16) {
                    a0 = ptrba[vec_idx + 10];
                    a1 = ptrba[vec_idx + 11];
                    res0_10 += a0 * b0; res1_10 += a0 * b1;
                    res0_11 += a1 * b0; res1_11 += a1 * b1;
                }
                if (vec_idx + 12 < 16) {
                    a0 = ptrba[vec_idx + 12];
                    a1 = ptrba[vec_idx + 13];
                    res0_12 += a0 * b0; res1_12 += a0 * b1;
                    res0_13 += a1 * b0; res1_13 += a1 * b1;
                }
                if (vec_idx + 14 < 16) {
                    a0 = ptrba[vec_idx + 14];
                    a1 = ptrba[vec_idx + 15];
                    res0_14 += a0 * b0; res1_14 += a0 * b1;
                    res0_15 += a1 * b0; res1_15 += a1 * b1;
                }
            }
            ptrba += 16;
            ptrbb += 2;
        }

        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        res0_8 *= alpha; res0_9 *= alpha; res0_10 *= alpha; res0_11 *= alpha;
        res0_12 *= alpha; res0_13 *= alpha; res0_14 *= alpha; res0_15 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        res1_4 *= alpha; res1_5 *= alpha; res1_6 *= alpha; res1_7 *= alpha;
        res1_8 *= alpha; res1_9 *= alpha; res1_10 *= alpha; res1_11 *= alpha;
        res1_12 *= alpha; res1_13 *= alpha; res1_14 *= alpha; res1_15 *= alpha;

        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
        C0[8] = res0_8; C0[9] = res0_9; C0[10] = res0_10; C0[11] = res0_11;
        C0[12] = res0_12; C0[13] = res0_13; C0[14] = res0_14; C0[15] = res0_15;
        C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
        C1[4] = res1_4; C1[5] = res1_5; C1[6] = res1_6; C1[7] = res1_7;
        C1[8] = res1_8; C1[9] = res1_9; C1[10] = res1_10; C1[11] = res1_11;
        C1[12] = res1_12; C1[13] = res1_13; C1[14] = res1_14; C1[15] = res1_15;

        temp = bk - off - 2;
        ptrba += temp * 16;
        ptrbb += temp * 2;
        C0 += 16;
        C1 += 16;
    }
}
