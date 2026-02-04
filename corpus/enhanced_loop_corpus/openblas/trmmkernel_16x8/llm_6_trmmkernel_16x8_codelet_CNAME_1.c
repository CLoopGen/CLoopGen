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
        float sum[16] = {0}; // Introduce local accumulation array to modify RAW/WAW dependencies
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k]; // Change access pattern: use k-indexed load instead of sequential
            a0 = ptrba[k * 16 + 0];
            a1 = ptrba[k * 16 + 1];
            sum[0] += a0 * b0;
            sum[1] += a1 * b0;
            sum[2] += ptrba[k * 16 + 2] * b0;
            sum[3] += ptrba[k * 16 + 3] * b0;
            sum[4] += ptrba[k * 16 + 4] * b0;
            sum[5] += ptrba[k * 16 + 5] * b0;
            sum[6] += ptrba[k * 16 + 6] * b0;
            sum[7] += ptrba[k * 16 + 7] * b0;
            sum[8] += ptrba[k * 16 + 8] * b0;
            sum[9] += ptrba[k * 16 + 9] * b0;
            sum[10] += ptrba[k * 16 + 10] * b0;
            sum[11] += ptrba[k * 16 + 11] * b0;
            sum[12] += ptrba[k * 16 + 12] * b0;
            sum[13] += ptrba[k * 16 + 13] * b0;
            sum[14] += ptrba[k * 16 + 14] * b0;
            sum[15] += ptrba[k * 16 + 15] * b0;
        }
        // Eliminate sequential dependency in accumulation by using independent sum[]
        res0_0 = sum[0] * alpha;
        res0_1 = sum[1] * alpha;
        res0_2 = sum[2] * alpha;
        res0_3 = sum[3] * alpha;
        res0_4 = sum[4] * alpha;
        res0_5 = sum[5] * alpha;
        res0_6 = sum[6] * alpha;
        res0_7 = sum[7] * alpha;
        res0_8 = sum[8] * alpha;
        res0_9 = sum[9] * alpha;
        res0_10 = sum[10] * alpha;
        res0_11 = sum[11] * alpha;
        res0_12 = sum[12] * alpha;
        res0_13 = sum[13] * alpha;
        res0_14 = sum[14] * alpha;
        res0_15 = sum[15] * alpha;

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

        temp = bk - off - 1;
        ptrba += temp * 16;
        ptrbb += temp;
        C0 += 16;
    }

    if (bm & 8) {
        ptrbb = bb;
        float acc8[8] = {0};
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            acc8[0] += ptrba[k * 8 + 0] * b0;
            acc8[1] += ptrba[k * 8 + 1] * b0;
            acc8[2] += ptrba[k * 8 + 2] * b0;
            acc8[3] += ptrba[k * 8 + 3] * b0;
            acc8[4] += ptrba[k * 8 + 4] * b0;
            acc8[5] += ptrba[k * 8 + 5] * b0;
            acc8[6] += ptrba[k * 8 + 6] * b0;
            acc8[7] += ptrba[k * 8 + 7] * b0;
        }
        C0[0] = acc8[0] * alpha;
        C0[1] = acc8[1] * alpha;
        C0[2] = acc8[2] * alpha;
        C0[3] = acc8[3] * alpha;
        C0[4] = acc8[4] * alpha;
        C0[5] = acc8[5] * alpha;
        C0[6] = acc8[6] * alpha;
        C0[7] = acc8[7] * alpha;

        temp = bk - off - 1;
        ptrba += temp * 8;
        ptrbb += temp;
        C0 += 8;
    }

    if (bm & 4) {
        ptrbb = bb;
        float acc4[4] = {0};
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            acc4[0] += ptrba[k * 4 + 0] * b0;
            acc4[1] += ptrba[k * 4 + 1] * b0;
            acc4[2] += ptrba[k * 4 + 2] * b0;
            acc4[3] += ptrba[k * 4 + 3] * b0;
        }
        C0[0] = acc4[0] * alpha;
        C0[1] = acc4[1] * alpha;
        C0[2] = acc4[2] * alpha;
        C0[3] = acc4[3] * alpha;

        temp = bk - off - 1;
        ptrba += temp * 4;
        ptrbb += temp;
        C0 += 4;
    }

    if (bm & 2) {
        ptrbb = bb;
        float acc2[2] = {0};
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            acc2[0] += ptrba[k * 2 + 0] * b0;
            acc2[1] += ptrba[k * 2 + 1] * b0;
        }
        C0[0] = acc2[0] * alpha;
        C0[1] = acc2[1] * alpha;

        temp = bk - off - 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 += 2;
    }

    if (bm & 1) {
        ptrbb = bb;
        float acc1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            acc1 += ptrba[k] * ptrbb[k];
        }
        C0[0] = acc1 * alpha;

        temp = bk - off - 1;
        ptrba += temp;
        ptrbb += temp;
        C0 += 1;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
