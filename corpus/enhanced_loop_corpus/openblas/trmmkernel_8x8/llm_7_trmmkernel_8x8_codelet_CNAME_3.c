#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG bm;
extern BLASLONG bk;
extern float alpha;
extern float *bb;
extern BLASLONG i;
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
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < bm / 8; i += 1) {
    ptrbb = bb;
    float acc0[8] = {0}, acc1[8] = {0}, acc2[8] = {0}, acc3[8] = {0};
    temp = off + 4;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        b2 = ptrbb[2];
        b3 = ptrbb[3];
        a0 = ptrba[0];
        acc0[0] += a0 * b0;
        acc1[0] += a0 * b1;
        acc2[0] += a0 * b2;
        acc3[0] += a0 * b3;
        a1 = ptrba[1];
        acc0[1] += a1 * b0;
        acc1[1] += a1 * b1;
        acc2[1] += a1 * b2;
        acc3[1] += a1 * b3;
        a0 = ptrba[2];
        acc0[2] += a0 * b0;
        acc1[2] += a0 * b1;
        acc2[2] += a0 * b2;
        acc3[2] += a0 * b3;
        a1 = ptrba[3];
        acc0[3] += a1 * b0;
        acc1[3] += a1 * b1;
        acc2[3] += a1 * b2;
        acc3[3] += a1 * b3;
        a0 = ptrba[4];
        acc0[4] += a0 * b0;
        acc1[4] += a0 * b1;
        acc2[4] += a0 * b2;
        acc3[4] += a0 * b3;
        a1 = ptrba[5];
        acc0[5] += a1 * b0;
        acc1[5] += a1 * b1;
        acc2[5] += a1 * b2;
        acc3[5] += a1 * b3;
        a0 = ptrba[6];
        acc0[6] += a0 * b0;
        acc1[6] += a0 * b1;
        acc2[6] += a0 * b2;
        acc3[6] += a0 * b3;
        a1 = ptrba[7];
        acc0[7] += a1 * b0;
        acc1[7] += a1 * b1;
        acc2[7] += a1 * b2;
        acc3[7] += a1 * b3;
        ptrba += 8;
        ptrbb += 4;
    }
    for (int j = 0; j < 8; j++) {
        acc0[j] *= alpha;
        acc1[j] *= alpha;
        acc2[j] *= alpha;
        acc3[j] *= alpha;
    }
    for (int j = 0; j < 8; j++) {
        C0[j] = acc0[j];
        C1[j] = acc1[j];
        C2[j] = acc2[j];
        C3[j] = acc3[j];
    }
    temp = bk - off;
    temp -= 4;
    ptrba += temp * 8;
    ptrbb += temp * 4;
    C0 += 8;
    C1 += 8;
    C2 += 8;
    C3 += 8;
}
}
