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
for (j = 0; j < (bn >> 1); j++) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < (bm >> 3); i++) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 
        res0_4 = res0_5 = res0_6 = res0_7 = 0.0f;
        for (k = 0; k < (off + 1) << 1; k += 2) {
            float b_val1 = ptrbb[k], b_val2 = ptrbb[k+1];
            res0_0 += ptrba[0] * b_val1; res0_1 += ptrba[1] * b_val1;
            res0_2 += ptrba[2] * b_val1; res0_3 += ptrba[3] * b_val1;
            res0_4 += ptrba[4] * b_val1; res0_5 += ptrba[5] * b_val1;
            res0_6 += ptrba[6] * b_val1; res0_7 += ptrba[7] * b_val1;

            res0_0 += ptrba[0] * b_val2; res0_1 += ptrba[1] * b_val2;
            res0_2 += ptrba[2] * b_val2; res0_3 += ptrba[3] * b_val2;
            res0_4 += ptrba[4] * b_val2; res0_5 += ptrba[5] * b_val2;
            res0_6 += ptrba[6] * b_val2; res0_7 += ptrba[7] * b_val2;
        }
        if ((off + 1) & 1) {
            b0 = ptrbb[(off + 1) << 1];
            res0_0 += ptrba[0] * b0; res0_1 += ptrba[1] * b0;
            res0_2 += ptrba[2] * b0; res0_3 += ptrba[3] * b0;
            res0_4 += ptrba[4] * b0; res0_5 += ptrba[5] * b0;
            res0_6 += ptrba[6] * b0; res0_7 += ptrba[7] * b0;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        C0[4] = res0_4; C0[5] = res0_5; C0[6] = res0_6; C0[7] = res0_7;
        ptrba += 8;
        C0 += 8;
    }
    BLASLONG rem = bm & 7;
    if (rem >= 4) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        for (k = 0; k < (off + 1); k++) {
            b0 = ptrbb[k];
            res0_0 += ptrba[0] * b0; res0_1 += ptrba[1] * b0;
            res0_2 += ptrba[2] * b0; res0_3 += ptrba[3] * b0;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        res0_2 *= alpha; res0_3 *= alpha;
        C0[0] = res0_0; C0[1] = res0_1; C0[2] = res0_2; C0[3] = res0_3;
        ptrba += 4; C0 += 4; rem -= 4;
    }
    if (rem >= 2) {
        res0_0 = res0_1 = 0;
        for (k = 0; k < (off + 1); k++) {
            b0 = bb[k];
            res0_0 += ptrba[0] * b0; res0_1 += ptrba[1] * b0;
        }
        C0[0] = res0_0 * alpha; C0[1] = res0_1 * alpha;
        ptrba += 2; C0 += 2; rem -= 2;
    }
    if (rem == 1) {
        res0_0 = 0;
        for (k = 0; k < (off + 1); k++) {
            res0_0 += ptrba[0] * bb[k];
        }
        C0[0] = res0_0 * alpha;
        C0 += 1;
    }
    bb += (bk << 1);
    C += (ldc << 1);
    j++;
}
if (bn & 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < (bm >> 3); i++) {
        ptrbb = bb;
        res0_0 = res0_1 = res0_2 = res0_3 = 
        res0_4 = res0_5 = res0_6 = res0_7 = 0;
        for (k = 0; k < off + 1; k++) {
            b0 = ptrbb[k];
            res0_0 += ptrba[0] * b0; res0_1 += ptrba[1] * b0;
            res0_2 += ptrba[2] * b0; res0_3 += ptrba[3] * b0;
            res0_4 += ptrba[4] * b0; res0_5 += ptrba[5] * b0;
            res0_6 += ptrba[6] * b0; res0_7 += ptrba[7] * b0;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        C0[0]=res0_0; C0[1]=res0_1; C0[2]=res0_2; C0[3]=res0_3;
        C0[4]=res0_4; C0[5]=res0_5; C0[6]=res0_6; C0[7]=res0_7;
        ptrba += 8; C0 += 8;
    }
    BLASLONG rem = bm & 7;
    if (rem >= 4) {
        res0_0 = res0_1 = res0_2 = res0_3 = 0;
        for (k = 0; k < off + 1; k++) {
            b0 = bb[k];
            res0_0 += ptrba[0]*b0; res0_1 += ptrba[1]*b0;
            res0_2 += ptrba[2]*b0; res0_3 += ptrba[3]*b0;
        }
        C0[0] = res0_0*alpha; C0[1] = res0_1*alpha;
        C0[2] = res0_2*alpha; C0[3] = res0_3*alpha;
        ptrba += 4; C0 += 4; rem -= 4;
    }
    if (rem >= 2) {
        res0_0 = res0_1 = 0;
        for (k = 0; k < off + 1; k++) {
            b0 = bb[k];
            res0_0 += ptrba[0]*b0; res0_1 += ptrba[1]*b0;
        }
        C0[0] = res0_0*alpha; C0[1] = res0_1*alpha;
        ptrba += 2; C0 += 2;
    }
    if (rem == 1) {
        res0_0 = 0;
        for (k = 0; k < off + 1; k++) {
            res0_0 += ptrba[0] * bb[k];
        }
        C0[0] = res0_0 * alpha;
    }
    C += ldc;
}
}
