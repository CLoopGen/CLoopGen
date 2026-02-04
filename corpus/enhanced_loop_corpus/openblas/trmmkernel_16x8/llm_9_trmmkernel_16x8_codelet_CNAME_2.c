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
for (i = 0; i < bm / 32; i += 1) {
    ptrbb = bb;
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 32; c++) {
            if (r == 0) {
                *((float*)(&res0_0) + c) = 0;
            } else if (r == 1) {
                *((float*)(&res1_0) + c) = 0;
            } else if (r == 2) {
                *((float*)(&res2_0) + c) = 0;
            } else {
                *((float*)(&res3_0) + c) = 0;
            }
        }
    }
    temp = off + 8;
    for (k = 0; k < temp; k++) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        b2 = ptrbb[2];
        b3 = ptrbb[3];
        b0 += b1; // Fused operation to increase arithmetic intensity
        b2 += b3;
        a0 = ptrba[0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b2;
        a1 = ptrba[1];
        res0_1 += a1 * b0;
        res1_1 += a1 * b2;
        a0 = ptrba[2];
        res0_2 += a0 * b0;
        res1_2 += a0 * b2;
        a1 = ptrba[3];
        res0_3 += a1 * b0;
        res1_3 += a1 * b2;
        a0 = ptrba[4];
        res0_4 += a0 * b0;
        res1_4 += a0 * b2;
        a1 = ptrba[5];
        res0_5 += a1 * b0;
        res1_5 += a1 * b2;
        a0 = ptrba[6];
        res0_6 += a0 * b0;
        res1_6 += a0 * b2;
        a1 = ptrba[7];
        res0_7 += a1 * b0;
        res1_7 += a1 * b2;
        a0 = ptrba[8];
        res2_0 += a0 * b0;
        res3_0 += a0 * b2;
        a1 = ptrba[9];
        res2_1 += a1 * b0;
        res3_1 += a1 * b2;
        a0 = ptrba[10];
        res2_2 += a0 * b0;
        res3_2 += a0 * b2;
        a1 = ptrba[11];
        res2_3 += a1 * b0;
        res3_3 += a1 * b2;
        a0 = ptrba[12];
        res2_4 += a0 * b0;
        res3_4 += a0 * b2;
        a1 = ptrba[13];
        res2_5 += a1 * b0;
        res3_5 += a1 * b2;
        a0 = ptrba[14];
        res2_6 += a0 * b0;
        res3_6 += a0 * b2;
        a1 = ptrba[15];
        res2_7 += a1 * b0;
        res3_7 += a1 * b2;
        a0 = ptrba[16];
        res0_8 += a0 * b0;
        res1_8 += a0 * b2;
        a1 = ptrba[17];
        res0_9 += a1 * b0;
        res1_9 += a1 * b2;
        a0 = ptrba[18];
        res0_10 += a0 * b0;
        res1_10 += a0 * b2;
        a1 = ptrba[19];
        res0_11 += a1 * b0;
        res1_11 += a1 * b2;
        a0 = ptrba[20];
        res0_12 += a0 * b0;
        res1_12 += a0 * b2;
        a1 = ptrba[21];
        res0_13 += a1 * b0;
        res1_13 += a1 * b2;
        a0 = ptrba[22];
        res0_14 += a0 * b0;
        res1_14 += a0 * b2;
        a1 = ptrba[23];
        res0_15 += a1 * b0;
        res1_15 += a1 * b2;
        a0 = ptrba[24];
        res2_8 += a0 * b0;
        res3_8 += a0 * b2;
        a1 = ptrba[25];
        res2_9 += a1 * b0;
        res3_9 += a1 * b2;
        a0 = ptrba[26];
        res2_10 += a0 * b0;
        res3_10 += a0 * b2;
        a1 = ptrba[27];
        res2_11 += a1 * b0;
        res3_11 += a1 * b2;
        a0 = ptrba[28];
        res2_12 += a0 * b0;
        res3_12 += a0 * b2;
        a1 = ptrba[29];
        res2_13 += a1 * b0;
        res3_13 += a1 * b2;
        a0 = ptrba[30];
        res2_14 += a0 * b0;
        res3_14 += a0 * b2;
        a1 = ptrba[31];
        res2_15 += a1 * b0;
        res3_15 += a1 * b2;
        ptrba = ptrba + 32;
        ptrbb = ptrbb + 4;
    }
    for (int c = 0; c < 16; c++) {
        *((float*)(&res0_0) + c) *= alpha;
        *((float*)(&res1_0) + c) *= alpha;
        *((float*)(&res2_0) + c) *= alpha;
        *((float*)(&res3_0) + c) *= alpha;
    }
    for (int c = 16; c < 32; c++) {
        *((float*)(&res0_0) + c) *= alpha;
        *((float*)(&res1_0) + c) *= alpha;
        *((float*)(&res2_0) + c) *= alpha;
        *((float*)(&res3_0) + c) *= alpha;
    }
    for (int c = 0; c < 16; c++) {
        C0[c] = *((float*)(&res0_0) + c);
        C1[c] = *((float*)(&res1_0) + c);
        C2[c] = *((float*)(&res2_0) + c);
        C3[c] = *((float*)(&res3_0) + c);
    }
    for (int c = 16; c < 32; c++) {
        C0[c] = *((float*)(&res0_0) + c);
        C1[c] = *((float*)(&res1_0) + c);
        C2[c] = *((float*)(&res2_0) + c);
        C3[c] = *((float*)(&res3_0) + c);
    }
    temp = bk - off;
    temp -= 8;
    ptrba += temp * 32;
    ptrbb += temp * 4;
    C0 = C0 + 32;
    C1 = C1 + 32;
    C2 = C2 + 32;
    C3 = C3 + 32;
}
}
