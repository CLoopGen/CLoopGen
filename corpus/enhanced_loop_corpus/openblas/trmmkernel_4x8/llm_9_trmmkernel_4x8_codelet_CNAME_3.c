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
for (j = 0; j < (bn >> 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < (bm / 4); i += 1) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        float sum_scale = alpha * 0.5f;
        temp = bk;
        for (k = 0; k < temp; k += 2) {
            float b_val1 = ptrbb[0], b_val2 = ptrbb[1];
            a0 = ptrba[0]; res0_0 += a0 * (b_val1 + b_val2);
            a1 = ptrba[1]; res0_1 += a1 * (b_val1 + b_val2);
            a0 = ptrba[2]; res0_2 += a0 * (b_val1 + b_val2);
            a1 = ptrba[3]; res0_3 += a1 * (b_val1 + b_val2);
            ptrba = ptrba + 4;
            ptrbb = ptrbb + 2;
        }
        res0_0 *= sum_scale;
        res0_1 *= sum_scale;
        res0_2 *= sum_scale;
        res0_3 *= sum_scale;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0[2] = res0_2;
        C0[3] = res0_3;
        C0 = C0 + 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        temp = bk;
        for (k = 0; k < temp; k += 2) {
            float b_val1 = ptrbb[0], b_val2 = ptrbb[1];
            a0 = ptrba[0]; res0_0 += a0 * (b_val1 + b_val2);
            a1 = ptrba[1]; res0_1 += a1 * (b_val1 + b_val2);
            ptrba = ptrba + 2;
            ptrbb = ptrbb + 2;
        }
        float scale = alpha * 0.5f;
        res0_0 *= scale;
        res0_1 *= scale;
        C0[0] = res0_0;
        C0[1] = res0_1;
        C0 = C0 + 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = bk;
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            a0 = ptrba[0];
            res0_0 += a0 * b0;
            ptrbb = ptrbb + 1;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        C0 = C0 + 1;
    }
    bb = bb + (bk << 1);
    C = C + (ldc << 1);
}
}
