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
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        res0_8 = 0;
        res0_9 = 0;
        res0_10 = 0;
        res0_11 = 0;
        res0_12 = 0;
        res0_13 = 0;
        res0_14 = 0;
        res0_15 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float sum_block[16];
            for (int idx = 0; idx < 16; idx++) {
                sum_block[idx] = ptrba[idx] * ptrbb[0];
            }
            res0_0 += sum_block[0];
            res0_1 += sum_block[1];
            res0_2 += sum_block[2];
            res0_3 += sum_block[3];
            res0_4 += sum_block[4];
            res0_5 += sum_block[5];
            res0_6 += sum_block[6];
            res0_7 += sum_block[7];
            res0_8 += sum_block[8];
            res0_9 += sum_block[9];
            res0_10 += sum_block[10];
            res0_11 += sum_block[11];
            res0_12 += sum_block[12];
            res0_13 += sum_block[13];
            res0_14 += sum_block[14];
            res0_15 += sum_block[15];
            ptrba = ptrba + 16;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        res0_8 *= alpha;
        res0_9 *= alpha;
        res0_10 *= alpha;
        res0_11 *= alpha;
        res0_12 *= alpha;
        res0_13 *= alpha;
        res0_14 *= alpha;
        res0_15 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0[4] = res0_4;
        C0[5] = res0_5;
        C0[6] = res0_6;
        C0[7] = res0_7;
        C0[8] = res0_8;
        C0[9] = res0_9;
        C0[10] = res0_10;
        C0[11] = res0_11;
        C0[12] = res0_12;
        C0[13] = res0_13;
        C0[14] = res0_14;
        C0[15] = res0_15;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 16;
        ptrbb += temp * 1;
        C0 = C0 + 16;
    }
    if (bm & 8) {
        ptrbb = bb;
        float acc8[8] = {0};
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[0];
            for (int idx = 0; idx < 8; idx++) {
                acc8[idx] += ptrba[idx] * b_val;
            }
            ptrba = ptrba + 8;
            ptrbb = ptrbb + 1;
        }
        for (int idx = 0; idx < 8; idx++) {
            acc8[idx] *= alpha;
        }
        C0[0] = acc8[0];
        C0[1] = acc8[1];
        C0[2] = acc8[2];
        C0[3] = acc8[3];
        C0[4] = acc8[4];
        C0[5] = acc8[5];
        C0[6] = acc8[6];
        C0[7] = acc8[7];
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 8;
        ptrbb += temp * 1;
        C0 = C0 + 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        float acc4[4] = {0};
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[0];
            for (int idx = 0; idx < 4; idx++) {
                acc4[idx] += ptrba[idx] * b_val;
            }
            ptrba = ptrba + 4;
            ptrbb = ptrbb + 1;
        }
        for (int idx = 0; idx < 4; idx++) {
            acc4[idx] *= alpha;
        }
        C0[0] = acc4[0];
        C0[1] = acc4[1];
        C0[2] = acc4[2];
        C0[3] = acc4[3];
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4;
        ptrbb += temp * 1;
        C0 = C0 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        float acc2[2] = {0};
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = ptrbb[0];
            acc2[0] += ptrba[0] * b_val;
            acc2[1] += ptrba[1] * b_val;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 1;
        }
        acc2[0] *= alpha;
        acc2[1] *= alpha;
        C0[0] = acc2[0];
        C0[1] = acc2[1];
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp * 1;
        C0 = C0 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        float acc1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            acc1 += ptrba[0] * ptrbb[0];
            ptrba = ptrba + 1;
            ptrbb = ptrbb + 1;
        }
        acc1 *= alpha;
        C0[0] = acc1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 1;
        ptrbb += temp * 1;
        C0 = C0 + 1;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
