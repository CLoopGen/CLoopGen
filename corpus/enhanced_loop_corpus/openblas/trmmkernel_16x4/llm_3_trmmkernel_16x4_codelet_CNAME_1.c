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
extern float res0_8;
extern float res0_9;
extern float res0_10;
extern float res0_11;
extern float res0_12;
extern float res0_13;
extern float res0_14;
extern float res0_15;
extern float a0;
extern float a1;
extern float b0;
extern BLASLONG off;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (bn & 1); j += 1) {
    C0 = C;
    ptrba = ba;
    for (i = 0; i < bm / 16; i += 1) {
        ptrbb = bb;
        res0_0 = 0;
        res0_1 = 0;
        res0_2 = 0;
        res0_3 = 0;
        res0_4 = 0;
        res0_5 = 0;
        res0_6 = 0;
        res0_7 = 0;
        res0_8 = 0;
        res0_9 = 0;
        res0_10 = 0;
        res0_11 = 0;
        res0_12 = 0;
        res0_13 = 0;
        res0_14 = 0;
        res0_15 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = *(ptrbb + k);
            float* a_row = ptrba + k * 16;
            res0_0 += a_row[0]  * b_val;
            res0_1 += a_row[1]  * b_val;
            res0_2 += a_row[2]  * b_val;
            res0_3 += a_row[3]  * b_val;
            res0_4 += a_row[4]  * b_val;
            res0_5 += a_row[5]  * b_val;
            res0_6 += a_row[6]  * b_val;
            res0_7 += a_row[7]  * b_val;
            res0_8 += a_row[8]  * b_val;
            res0_9 += a_row[9]  * b_val;
            res0_10 += a_row[10] * b_val;
            res0_11 += a_row[11] * b_val;
            res0_12 += a_row[12] * b_val;
            res0_13 += a_row[13] * b_val;
            res0_14 += a_row[14] * b_val;
            res0_15 += a_row[15] * b_val;
        }
        res0_0 *= alpha;
        res0_1 *= alpha;
        res0_2 *= alpha;
        res0_3 *= alpha;
        res0_4 *= alpha;
        res0_5 *= alpha;
        res0_6 *= alpha;
        res0_7 *= alpha;
        res0_8 *= alpha;
        res0_9 *= alpha;
        res0_10 *= alpha;
        res0_11 *= alpha;
        res0_12 *= alpha;
        res0_13 *= alpha;
        res0_14 *= alpha;
        res0_15 *= alpha;
        float* c_row = C0;
        c_row[0]  = res0_0;  c_row[1]  = res0_1;  c_row[2]  = res0_2;  c_row[3]  = res0_3;
        c_row[4]  = res0_4;  c_row[5]  = res0_5;  c_row[6]  = res0_6;  c_row[7]  = res0_7;
        c_row[8]  = res0_8;  c_row[9]  = res0_9;  c_row[10] = res0_10; c_row[11] = res0_11;
        c_row[12] = res0_12; c_row[13] = res0_13; c_row[14] = res0_14; c_row[15] = res0_15;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 16 + 16;
        ptrbb += temp + 1;
        C0 += 16;
    }
    if (bm & 8) {
        ptrbb = bb;
        res0_0 = 0; res0_1 = 0; res0_2 = 0; res0_3 = 0;
        res0_4 = 0; res0_5 = 0; res0_6 = 0; res0_7 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = *(ptrbb + k);
            float* a_row = ptrba + k * 8;
            res0_0 += a_row[0] * b_val;
            res0_1 += a_row[1] * b_val;
            res0_2 += a_row[2] * b_val;
            res0_3 += a_row[3] * b_val;
            res0_4 += a_row[4] * b_val;
            res0_5 += a_row[5] * b_val;
            res0_6 += a_row[6] * b_val;
            res0_7 += a_row[7] * b_val;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        res0_4 *= alpha; res0_5 *= alpha; res0_6 *= alpha; res0_7 *= alpha;
        float* c_row = C0;
        c_row[0] = res0_0; c_row[1] = res0_1; c_row[2] = res0_2; c_row[3] = res0_3;
        c_row[4] = res0_4; c_row[5] = res0_5; c_row[6] = res0_6; c_row[7] = res0_7;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 8 + 8;
        ptrbb += temp + 1;
        C0 += 8;
    }
    if (bm & 4) {
        ptrbb = bb;
        res0_0 = 0; res0_1 = 0; res0_2 = 0; res0_3 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = *(ptrbb + k);
            float* a_row = ptrba + k * 4;
            res0_0 += a_row[0] * b_val;
            res0_1 += a_row[1] * b_val;
            res0_2 += a_row[2] * b_val;
            res0_3 += a_row[3] * b_val;
        }
        res0_0 *= alpha; res0_1 *= alpha; res0_2 *= alpha; res0_3 *= alpha;
        float* c_row = C0;
        c_row[0] = res0_0; c_row[1] = res0_1; c_row[2] = res0_2; c_row[3] = res0_3;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 4 + 4;
        ptrbb += temp + 1;
        C0 += 4;
    }
    if (bm & 2) {
        ptrbb = bb;
        res0_0 = 0; res0_1 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = *(ptrbb + k);
            float* a_row = ptrba + k * 2;
            res0_0 += a_row[0] * b_val;
            res0_1 += a_row[1] * b_val;
        }
        res0_0 *= alpha; res0_1 *= alpha;
        float* c_row = C0;
        c_row[0] = res0_0; c_row[1] = res0_1;
        temp = bk - off;
        temp -= 1;
        ptrba += temp * 2 + 2;
        ptrbb += temp + 1;
        C0 += 2;
    }
    if (bm & 1) {
        ptrbb = bb;
        res0_0 = 0;
        temp = off + 1;
        for (k = 0; k < temp; k++) {
            float b_val = *(ptrbb + k);
            float* a_row = ptrba + k;
            res0_0 += a_row[0] * b_val;
        }
        res0_0 *= alpha;
        C0[0] = res0_0;
        temp = bk - off;
        temp -= 1;
        ptrba += temp + 1;
        ptrbb += temp + 1;
        C0 += 1;
    }
    k = (bk << 0);
    bb = bb + k;
    C = C + ldc;
}
}
