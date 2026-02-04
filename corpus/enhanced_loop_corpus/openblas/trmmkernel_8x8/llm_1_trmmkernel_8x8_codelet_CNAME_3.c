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
    for (int m = 0; m < 8; m++) {
        float* res_ptr;
        switch(m) {
            case 0: res_ptr = &res0_0; break;
            case 1: res_ptr = &res0_1; break;
            case 2: res_ptr = &res0_2; break;
            case 3: res_ptr = &res0_3; break;
            case 4: res_ptr = &res0_4; break;
            case 5: res_ptr = &res0_5; break;
            case 6: res_ptr = &res0_6; break;
            case 7: res_ptr = &res0_7; break;
        }
        *res_ptr = 0;
    }
    for (int m = 0; m < 8; m++) {
        float* res_ptr;
        switch(m) {
            case 0: res_ptr = &res1_0; break;
            case 1: res_ptr = &res1_1; break;
            case 2: res_ptr = &res1_2; break;
            case 3: res_ptr = &res1_3; break;
            case 4: res_ptr = &res1_4; break;
            case 5: res_ptr = &res1_5; break;
            case 6: res_ptr = &res1_6; break;
            case 7: res_ptr = &res1_7; break;
        }
        *res_ptr = 0;
    }
    for (int m = 0; m < 8; m++) {
        float* res_ptr;
        switch(m) {
            case 0: res_ptr = &res2_0; break;
            case 1: res_ptr = &res2_1; break;
            case 2: res_ptr = &res2_2; break;
            case 3: res_ptr = &res2_3; break;
            case 4: res_ptr = &res2_4; break;
            case 5: res_ptr = &res2_5; break;
            case 6: res_ptr = &res2_6; break;
            case 7: res_ptr = &res2_7; break;
        }
        *res_ptr = 0;
    }
    for (int m = 0; m < 8; m++) {
        float* res_ptr;
        switch(m) {
            case 0: res_ptr = &res3_0; break;
            case 1: res_ptr = &res3_1; break;
            case 2: res_ptr = &res3_2; break;
            case 3: res_ptr = &res3_3; break;
            case 4: res_ptr = &res3_4; break;
            case 5: res_ptr = &res3_5; break;
            case 6: res_ptr = &res3_6; break;
            case 7: res_ptr = &res3_7; break;
        }
        *res_ptr = 0;
    }
    temp = off + 4;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        b2 = ptrbb[2];
        b3 = ptrbb[3];
        float a_vals[8];
        for (int idx = 0; idx < 8; idx++) {
            a_vals[idx] = ptrba[idx];
        }
        res0_0 += a_vals[0] * b0;
        res1_0 += a_vals[0] * b1;
        res2_0 += a_vals[0] * b2;
        res3_0 += a_vals[0] * b3;
        res0_1 += a_vals[1] * b0;
        res1_1 += a_vals[1] * b1;
        res2_1 += a_vals[1] * b2;
        res3_1 += a_vals[1] * b3;
        res0_2 += a_vals[2] * b0;
        res1_2 += a_vals[2] * b1;
        res2_2 += a_vals[2] * b2;
        res3_2 += a_vals[2] * b3;
        res0_3 += a_vals[3] * b0;
        res1_3 += a_vals[3] * b1;
        res2_3 += a_vals[3] * b2;
        res3_3 += a_vals[3] * b3;
        res0_4 += a_vals[4] * b0;
        res1_4 += a_vals[4] * b1;
        res2_4 += a_vals[4] * b2;
        res3_4 += a_vals[4] * b3;
        res0_5 += a_vals[5] * b0;
        res1_5 += a_vals[5] * b1;
        res2_5 += a_vals[5] * b2;
        res3_5 += a_vals[5] * b3;
        res0_6 += a_vals[6] * b0;
        res1_6 += a_vals[6] * b1;
        res2_6 += a_vals[6] * b2;
        res3_6 += a_vals[6] * b3;
        res0_7 += a_vals[7] * b0;
        res1_7 += a_vals[7] * b1;
        res2_7 += a_vals[7] * b2;
        res3_7 += a_vals[7] * b3;
        ptrba = ptrba + 8;
        ptrbb = ptrbb + 4;
    }
    for (int j = 0; j < 8; j++) {
        float* src_res[] = {&res0_0, &res0_1, &res0_2, &res0_3, &res0_4, &res0_5, &res0_6, &res0_7};
        C0[j] = src_res[j][0] * alpha;
    }
    for (int j = 0; j < 8; j++) {
        float* src_res[] = {&res1_0, &res1_1, &res1_2, &res1_3, &res1_4, &res1_5, &res1_6, &res1_7};
        C1[j] = src_res[j][0] * alpha;
    }
    for (int j = 0; j < 8; j++) {
        float* src_res[] = {&res2_0, &res2_1, &res2_2, &res2_3, &res2_4, &res2_5, &res2_6, &res2_7};
        C2[j] = src_res[j][0] * alpha;
    }
    for (int j = 0; j < 8; j++) {
        float* src_res[] = {&res3_0, &res3_1, &res3_2, &res3_3, &res3_4, &res3_5, &res3_6, &res3_7};
        C3[j] = src_res[j][0] * alpha;
    }
    temp = bk - off;
    temp -= 4;
    ptrba += temp * 8;
    ptrbb += temp * 4;
    C0 = C0 + 8;
    C1 = C1 + 8;
    C2 = C2 + 8;
    C3 = C3 + 8;
}
}
