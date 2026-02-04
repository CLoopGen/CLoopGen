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
    for (i = 0; i < bm / 8; i += 1) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            a0 = ptrba[k * 8 + 0];
            a1 = ptrba[k * 8 + 1];
            res0_0 += a0 * b0;
            res0_1 += a1 * b0;
            res0_2 += ptrba[k * 8 + 2] * b0;
            res0_3 += ptrba[k * 8 + 3] * b0;
            res0_4 += ptrba[k * 8 + 4] * b0;
            res0_5 += ptrba[k * 8 + 5] * b0;
            res0_6 += ptrba[k * 8 + 6] * b0;
            res0_7 += ptrba[k * 8 + 7] * b0;
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
        ptrbb += temp;
        C0 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            res0_0 += ptrba[k * 4 + 0] * b0;
            res0_1 += ptrba[k * 4 + 1] * b0;
            res0_2 += ptrba[k * 4 + 2] * b0;
            res0_3 += ptrba[k * 4 + 3] * b0;
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
        ptrbb += temp;
        C0 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[k];
            res0_0 += ptrba[k * 2 + 0] * b0;
            res0_1 += ptrba[k * 2 + 1] * b0;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp;
        C0 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            res0_0 += ptrba[k] * ptrbb[k];
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp;
        ptrbb += temp;
        C0 += 1;
    }
    bb += bk;
    C += ldc;
}
}
