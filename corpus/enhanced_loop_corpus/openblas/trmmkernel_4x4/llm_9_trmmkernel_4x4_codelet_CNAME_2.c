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
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn >> 1); j += 2) {  // Double the step, reduce trip count
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 8; i += 1) {  // Increase unrolling factor to 8
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        float res0_4 = 0, res0_5 = 0, res0_6 = 0, res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0]; res0_0 += a0 * b0;
            a1 = ptrba[1]; res0_1 += a1 * b0;
            a0 = ptrba[2]; res0_2 += a0 * b0;
            a1 = ptrba[3]; res0_3 += a1 * b0;
            a0 = ptrba[4]; res0_4 += a0 * b0;
            a1 = ptrba[5]; res0_5 += a1 * b0;
            a0 = ptrba[6]; res0_6 += a0 * b0;
            a1 = ptrba[7]; res0_7 += a1 * b0;
            ptrba = ptrba + 8;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha;
        res0_6 *= alpha; res0_7 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1;
        C0[2] = res0_2; C0[3] = res0_3;
        C0[4] = res0_4; C0[5] = res0_5;
        C0[6] = res0_6; C0[7] = res0_7;
        temp = bk - off; temp -= 1;
        ptrba += temp * 8;
        ptrbb += temp * 1;
        C0 = C0 + 8;
    }
    // Handle remaining columns with reduced conditions
    for (i = (bm / 8) * 8; i < bm; i += 4) {
        if (bm - i >= 4) {
            ptrbb = bb;
            res0_0 = res0_1 = res0_2 = res0_3 = 0;
            temp = off + 1;
            for (k = 0; k < temp; k++) {
                b0 = ptrbb[0];
                a0 = ptrba[0]; res0_0 += a0 * b0;
                a1 = ptrba[1]; res0_1 += a1 * b0;
                a0 = ptrba[2]; res0_2 += a0 * b0;
                a1 = ptrba[3]; res0_3 += a1 * b0;
                ptrba += 4; ptrbb++;
            }
            C0[0] = res0_0 * alpha;
            C0[1] = res0_1 * alpha;
            C0[2] = res0_2 * alpha;
            C0[3] = res0_3 * alpha;
            C0 += 4;
        }
    }
    bb = bb + (bk << 1);  // Advance bb by 2*bk per outer iteration
    C = C + (ldc << 1);   // Advance C by 2*ldc
}
}
