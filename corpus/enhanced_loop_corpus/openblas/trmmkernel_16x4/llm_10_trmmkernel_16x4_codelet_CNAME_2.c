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
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float res1_8;
extern float res1_9;
extern float res1_10;
extern float res1_11;
extern float res1_12;
extern float res1_13;
extern float res1_14;
extern float res1_15;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < bm / 32; i += 1) {
    ptrbb = bb;
    for (BLASLONG j = 0; j < 32; j++) {
        ((float*)(&res0_0))[j] = 0.0f;
        ((float*)(&res1_0))[j] = 0.0f;
    }
    temp = off + 2;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        #pragma unroll
        for (BLASLONG j = 0; j < 32; j += 2) {
            a0 = ptrba[j];
            a1 = ptrba[j+1];
            res0_0 += a0 * b0; res1_0 += a0 * b1;
            res0_1 += a1 * b0; res1_1 += a1 * b1;
        }
        ptrba = ptrba + 32;
        ptrbb = ptrbb + 2;
    }
    #pragma unroll
    for (BLASLONG j = 0; j < 32; j++) {
        ((float*)(&res0_0))[j] *= alpha;
        ((float*)(&res1_0))[j] *= alpha;
    }
    #pragma unroll
    for (BLASLONG j = 0; j < 32; j++) {
        C0[j] = ((float*)(&res0_0))[j];
        C1[j] = ((float*)(&res1_0))[j];
    }
    temp = bk - off;
    temp -= 2;
    ptrba += temp * 32;
    ptrbb += temp * 2;
    C0 = C0 + 32;
    C1 = C1 + 32;
}
}
