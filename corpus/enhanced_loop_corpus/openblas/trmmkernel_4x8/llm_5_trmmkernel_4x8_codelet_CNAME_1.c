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
extern BLASLONG offset;
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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG off;
extern BLASLONG temp;
extern _Bool left;
extern _Bool backwards;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 4); j += 4) {
    C0 = C;
    C1 = C0 + ldc;
    C2 = C1 + ldc;
    C3 = C2 + ldc;
    off = backwards ? offset : (left ? offset : 0);
    ptrba = ba;
    for (i = 0; i < bm / 4; i++) {
        ptrbb = bb;
        if (backwards) {
            ptrba += off * 4;
            ptrbb += off * 4;
        }
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        res1_0 = res1_1 = res1_2 = res1_3 = 0;
        res2_0 = res2_1 = res2_2 = res2_3 = 0;
        res3_0 = res3_1 = res3_2 = res3_3 = 0;
        temp = (backwards || left) ? bk - off : off + 4;
        for (k = 0; k < temp; k++) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = *ptrba;
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            a1 = ptrba[1];
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
            a0 = ptrba[2];
            res0_2 += a0 * b0; res1_2 += a0 * b1; res2_2 += a0 * b2; res3_2 += a0 * b3;
            a1 = ptrba[3];
            res0_3 += a1 * b0; res1_3 += a1 * b1; res2_3 += a1 * b2; res3_3 += a1 * b3;
            ptrba += 4; ptrbb += 4;
        }
        float scale = alpha;
        res0_0 *= scale; res0_1 *= scale; res0_2 *= scale; res0_3 *= scale;
        res1_0 *= scale; res1_1 *= scale; res1_2 *= scale; res1_3 *= scale;
        res2_0 *= scale; res2_1 *= scale; res2_2 *= scale; res2_3 *= scale;
        res3_0 *= scale; res3_1 *= scale; res3_2 *= scale; res3_3 *= scale;
        *C0 = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        *C1 = res1_0; C1[1] = res1_1; C1[2] = res1_2; C1[3] = res1_3;
        *C2 = res2_0; C2[1] = res2_1; C2[2] = res2_2; C2[3] = res2_3;
        *C3 = res3_0; C3[1] = res3_1; C3[2] = res3_2; C3[3] = res3_3;
        if (!backwards) {
            temp = bk - off - 4;
            ptrba += temp * 4;
            ptrbb += temp * 4;
        }
        C0 += 4; C1 += 4; C2 += 4; C3 += 4;
    }
    temp = bk - off - 4;
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = res0_1 = res1_0 = res1_1 = res2_0 = res2_1 = res3_0 = res3_1 = 0;
        for (k = 0; k < off + 4; ++k) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = *ptrba;
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            a1 = ptrba[1];
            res0_1 += a1 * b0; res1_1 += a1 * b1; res2_1 += a1 * b2; res3_1 += a1 * b3;
            ptrba += 2; ptrbb += 4;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        res1_0 *= alpha; res1_1 *= alpha;
        res2_0 *= alpha; res2_1 *= alpha;
        res3_0 *= alpha; res3_1 *= alpha;
        *C0 = res0_0; C0[1] = res0_1;
        *C1 = res1_0; C1[1] = res1_1;
        *C2 = res2_0; C2[1] = res2_1;
        *C3 = res3_0; C3[1] = res3_1;
        ptrba += temp * 2;
        ptrbb += temp * 4;
        C0 += 2; C1 += 2; C2 += 2; C3 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = res1_0 = res2_0 = res3_0 = 0;
        for (k = 0; k < off + 4; ++k) {
            b0 = *ptrbb; b1 = ptrbb[1]; b2 = ptrbb[2]; b3 = ptrbb[3];
            a0 = *ptrba;
            res0_0 += a0 * b0; res1_0 += a0 * b1; res2_0 += a0 * b2; res3_0 += a0 * b3;
            ptrba++; ptrbb += 4;
        }
        res0_0 *= alpha; res1_0 *= alpha; res2_0 *= alpha; res3_0 *= alpha;
        *C0 = res0_0; *C1 = res1_0; *C2 = res2_0; *C3 = res3_0;
        ptrba += temp;
        ptrbb += temp * 4;
        C0++; C1++; C2++; C3++;
    }
    bb += bk * 4;
    C += ldc * 4;
}
}
