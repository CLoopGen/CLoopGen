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
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res2_4;
extern float res2_5;
extern float res2_6;
extern float res2_7;
extern float res2_8;
extern float res2_9;
extern float res2_10;
extern float res2_11;
extern float res2_12;
extern float res2_13;
extern float res2_14;
extern float res2_15;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float res3_4;
extern float res3_5;
extern float res3_6;
extern float res3_7;
extern float res3_8;
extern float res3_9;
extern float res3_10;
extern float res3_11;
extern float res3_12;
extern float res3_13;
extern float res3_14;
extern float res3_15;
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
for (i = 0; i < bm / 16; i += 1) {
    ptrbb = bb;
    for (int r = 0; r < 16; r++) {
        *((float*)&res0_0 + r) = 0.0f;
        *((float*)&res1_0 + r) = 0.0f;
        *((float*)&res2_0 + r) = 0.0f;
        *((float*)&res3_0 + r) = 0.0f;
    }
    temp = off + 4;
    for (k = 0; k < temp; k++) {
        float b_vec[4];
        for (int j = 0; j < 4; j++) {
            b_vec[j] = ptrbb[j];
        }
        for (int col = 0; col < 16; col++) {
            float a_val = ptrba[col];
            float* res_ptr = (float*)(&res0_0 + col);
            res_ptr[ 0] += a_val * b_vec[0];
            res_ptr[16] += a_val * b_vec[1];
            res_ptr[32] += a_val * b_vec[2];
            res_ptr[48] += a_val * b_vec[3];
        }
        ptrba += 16;
        ptrbb += 4;
    }
    for (int col = 0; col < 16; col++) {
        float* res_ptr = (float*)(&res0_0 + col);
        for (int row = 0; row < 4; row++) {
            res_ptr[row * 16] *= alpha;
        }
    }
    for (int col = 0; col < 16; col++) {
        C0[col] = ((float*)&res0_0)[col];
        C1[col] = ((float*)&res1_0)[col];
        C2[col] = ((float*)&res2_0)[col];
        C3[col] = ((float*)&res3_0)[col];
    }
    temp = bk - off;
    temp -= 4;
    ptrba += temp * 16;
    ptrbb += temp * 4;
    C0 += 16;
    C1 += 16;
    C2 += 16;
    C3 += 16;
}
}
