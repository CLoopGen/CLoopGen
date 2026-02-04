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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
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
    for (i = 0; i < bm / 2; i += 1) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res1_0 = 0;
        res1_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            a1 = ptrba[1];
            res0_1 += a1 * b0;
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C1[0] = res1_0;
        C1[1] = res1_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2;
        ptrbb += temp * 1;
        C0 = C0 + 2;
        C1 = C1 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            ptrba = ptrba + 1;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 1;
        ptrbb += temp * 1;
        C0 = C0 + 1;
        C1 = C1 + 1;
    }
    k = bk;
    bb = bb + k;
    i = ldc;
    C = C + i;
}
}
