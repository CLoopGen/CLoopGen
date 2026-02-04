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
        // Interleaved memory access pattern: process two k iterations at once
        for (k = 0; k < temp - 1; k += 2) {
            float b0_0 = ptrbb[0];
            float b0_1 = ptrbb[1];
            const float* pa0 = ptrba;
            const float* pa1 = ptrba + 16;
            res0_0 += pa0[0] * b0_0 + pa1[0] * b0_1;
            res0_1 += pa0[1] * b0_0 + pa1[1] * b0_1;
            res0_2 += pa0[2] * b0_0 + pa1[2] * b0_1;
            res0_3 += pa0[3] * b0_0 + pa1[3] * b0_1;
            res0_4 += pa0[4] * b0_0 + pa1[4] * b0_1;
            res0_5 += pa0[5] * b0_0 + pa1[5] * b0_1;
            res0_6 += pa0[6] * b0_0 + pa1[6] * b0_1;
            res0_7 += pa0[7] * b0_0 + pa1[7] * b0_1;
            res0_8 += pa0[8] * b0_0 + pa1[8] * b0_1;
            res0_9 += pa0[9] * b0_0 + pa1[9] * b0_1;
            res0_10 += pa0[10] * b0_0 + pa1[10] * b0_1;
            res0_11 += pa0[11] * b0_0 + pa1[11] * b0_1;
            res0_12 += pa0[12] * b0_0 + pa1[12] * b0_1;
            res0_13 += pa0[13] * b0_0 + pa1[13] * b0_1;
            res0_14 += pa0[14] * b0_0 + pa1[14] * b0_1;
            res0_15 += pa0[15] * b0_0 + pa1[15] * b0_1;
            ptrba = ptrba + 32;
            ptrbb = ptrbb + 2;
        }
        if (k < temp) { // Handle odd leftover iteration
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            a0 = ptrba[2];
            res0_2 += a0 * b0;
            a1 = ptrba[3];
            res0_3 += a1 * b0;
            a0 = ptrba[4];
            res0_4 += a0 * b0;
            a1 = ptrba[5];
            res0_5 += a1 * b0;
            a0 = ptrba[6];
            res0_6 += a0 * b0;
            a1 = ptrba[7];
            res0_7 += a1 * b0;
            a0 = ptrba[8];
            res0_8 += a0 * b0;
            a1 = ptrba[9];
            res0_9 += a1 * b0;
            a0 = ptrba[10];
            res0_10 += a0 * b0;
            a1 = ptrba[11];
            res0_11 += a1 * b0;
            a0 = ptrba[12];
            res0_12 += a0 * b0;
            a1 = ptrba[13];
            res0_13 += a1 * b0;
            a0 = ptrba[14];
            res0_14 += a0 * b0;
            a1 = ptrba[15];
            res0_15 += a1 * b0;
            ptrba += 16;
            ptrbb += 1;
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
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp - 1; k += 2) {
            float b0_0 = ptrbb[0], b0_1 = ptrbb[1];
            const float* pa0 = ptrba;
            const float* pa1 = ptrba + 8;
            res0_0 += pa0[0] * b0_0 + pa1[0] * b0_1;
            res0_1 += pa0[1] * b0_0 + pa1[1] * b0_1;
            res0_2 += pa0[2] * b0_0 + pa1[2] * b0_1;
            res0_3 += pa0[3] * b0_0 + pa1[3] * b0_1;
            res0_4 += pa0[4] * b0_0 + pa1[4] * b0_1;
            res0_5 += pa0[5] * b0_0 + pa1[5] * b0_1;
            res0_6 += pa0[6] * b0_0 + pa1[6] * b0_1;
            res0_7 += pa0[7] * b0_0 + pa1[7] * b0_1;
            ptrba += 16;
            ptrbb += 2;
        }
        if (k < temp) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            a0 = ptrba[2];
            res0_2 += a0 * b0;
            a1 = ptrba[3];
            res0_3 += a1 * b0;
            a0 = ptrba[4];
            res0_4 += a0 * b0;
            a1 = ptrba[5];
            res0_5 += a1 * b0;
            a0 = ptrba[6];
            res0_6 += a0 * b0;
            a1 = ptrba[7];
            res0_7 += a1 * b0;
            ptrba += 8;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0[4] = res0_4;
        C0[5] = res0_5;
        C0[6] = res0_6;
        C0[7] = res0_7;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 8;
        ptrbb += temp * 1;
        C0 = C0 + 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        temp = off + 1;
        for (k = 0; k < temp - 1; k += 2) {
            float b0_0 = ptrbb[0], b0_1 = ptrbb[1];
            const float* pa0 = ptrba;
            const float* pa1 = ptrba + 4;
            res0_0 += pa0[0] * b0_0 + pa1[0] * b0_1;
            res0_1 += pa0[1] * b0_0 + pa1[1] * b0_1;
            res0_2 += pa0[2] * b0_0 + pa1[2] * b0_1;
            res0_3 += pa0[3] * b0_0 + pa1[3] * b0_1;
            ptrba += 8;
            ptrbb += 2;
        }
        if (k < temp) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            a0 = ptrba[2];
            res0_2 += a0 * b0;
            a1 = ptrba[3];
            res0_3 += a1 * b0;
            ptrba += 4;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4;
        ptrbb += temp * 1;
        C0 = C0 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp - 1; k += 2) {
            float b0_0 = ptrbb[0], b0_1 = ptrbb[1];
            const float* pa0 = ptrba;
            const float* pa1 = ptrba + 2;
            res0_0 += pa0[0] * b0_0 + pa1[0] * b0_1;
            res0_1 += pa0[1] * b0_0 + pa1[1] * b0_1;
            ptrba += 4;
            ptrbb += 2;
        }
        if (k < temp) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            ptrba += 2;
            ptrbb += 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp * 1;
        C0 = C0 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            ptrba++;
            ptrbb++;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp;
        ptrbb += temp;
        C0++;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
