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
for (i = 0; i < bm / 16; i += 1) {
    ptrbb = bb;
    for (BLASLONG ii = 0; ii < 16; ii++) {
        *(float*)((char*)(&res0_0) + ii * sizeof(float)) = 0.0f;
        *(float*)((char*)(&res1_0) + ii * sizeof(float)) = 0.0f;
    }
    temp = off + 2;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        for (BLASLONG j = 0; j < 16; j++) {
            float a_val = ptrba[j];
            *(float*)((char*)(&res0_0) + j * sizeof(float)) += a_val * b0;
            *(float*)((char*)(&res1_0) + j * sizeof(float)) += a_val * b1;
        }
        ptrba += 16;
        ptrbb += 2;
    }
    for (BLASLONG j = 0; j < 16; j++) {
        float scaled_res0 = *(float*)((char*)(&res0_0) + j * sizeof(float)) * alpha;
        float scaled_res1 = *(float*)((char*)(&res1_0) + j * sizeof(float)) * alpha;
        C0[j] = scaled_res0;
        C1[j] = scaled_res1;
    }
    temp = bk - off - 2;
    ptrba += temp * 16;
    ptrbb += temp * 2;
    C0 += 16;
    C1 += 16;
}
}
