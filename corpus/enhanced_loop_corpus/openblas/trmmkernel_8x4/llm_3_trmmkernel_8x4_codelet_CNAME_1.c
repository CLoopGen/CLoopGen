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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 2); j += 2) {
    C0 = C;
    C1 = C0 + ldc;
    ptrba = ba;
    BLASLONG idx_a, idx_b;
    for (i = 0; i < bm / 8; i += 1) {
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
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            idx_b = k * 2;
            b0 = bb[idx_b];
            b1 = bb[idx_b + 1];
            idx_a = k * 8;
            a0 = ptrba[idx_a];
            a1 = ptrba[idx_a + 1];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
            a0 = ptrba[idx_a + 2];
            a1 = ptrba[idx_a + 3];
            res0_2 += a0 * b0;
            res1_2 += a0 * b1;
            res0_3 += a1 * b0;
            res1_3 += a1 * b1;
            a0 = ptrba[idx_a + 4];
            a1 = ptrba[idx_a + 5];
            res0_4 += a0 * b0;
            res1_4 += a0 * b1;
            res0_5 += a1 * b0;
            res1_5 += a1 * b1;
            a0 = ptrba[idx_a + 6];
            a1 = ptrba[idx_a + 7];
            res0_6 += a0 * b0;
            res1_6 += a0 * b1;
            res0_7 += a1 * b0;
            res1_7 += a1 * b1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        res1_0 *= alpha;
        res1_1 *= alpha;
        res1_2 *= alpha;
        res1_3 *= alpha;
        res1_4 *= alpha;
        res1_5 *= alpha;
        res1_6 *= alpha;
        res1_7 *= alpha;
        for (BLASLONG m = 0; m < 8; m++) {
            C0[m] = *((float*)&res0_0 + m);
            C1[m] = *((float*)&res1_0 + m);
        }
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 8 + 8;
        C0 += 8;
        C1 += 8;
    }
    if (bm & 4) {
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            idx_b = k * 2;
            b0 = bb[idx_b];
            b1 = bb[idx_b + 1];
            idx_a = k * 4;
            a0 = ptrba[idx_a];
            a1 = ptrba[idx_a + 1];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
            a0 = ptrba[idx_a + 2];
            a1 = ptrba[idx_a + 3];
            res0_2 += a0 * b0;
            res1_2 += a0 * b1;
            res0_3 += a1 * b0;
            res1_3 += a1 * b1;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha; res1_2 *= alpha; res1_3 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C1[0] = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 4 + 4;
        C0 += 4;
        C1 += 4;
    }
    if (bm & 2) {
        res0_0 = res0_1 = res1_0 = res1_1 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            idx_b = k * 2;
            b0 = bb[idx_b];
            b1 = bb[idx_b + 1];
            idx_a = k * 2;
            a0 = ptrba[idx_a];
            a1 = ptrba[idx_a + 1];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
            res0_1 += a1 * b0;
            res1_1 += a1 * b1;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1;
        C1[0] = res1_0; C1[1] = res1_1;
        temp = bk - off;
        temp -= 2;
        ptrba += temp * 2 + 2;
        C0 += 2;
        C1 += 2;
    }
    if (bm & 1) {
        res0_0 = res1_0 = 0;
        temp = off + 2;
        for (k = 0; k < temp; k++) {
            idx_b = k * 2;
            b0 = bb[idx_b];
            b1 = bb[idx_b + 1];
            a0 = ptrba[k];
            res0_0 += a0 * b0;
            res1_0 += a0 * b1;
        }
        res0_0 *= alpha;
        res1_0 *= alpha;
        C0[0] = res0_0;
        C1[0] = res1_0;
        temp = bk - off;
        temp -= 2;
        ptrba += temp + 1;
        C0++;
        C1++;
    }
    k = (bk << 1);
    bb += k;
    C += (ldc << 1);
}
}
