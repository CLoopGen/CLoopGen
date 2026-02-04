#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
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
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < temp; k += 2) {
    if (k + 1 >= temp) break;

    // Load two sets of b values for higher computational density
    float b0_0 = ptrbb[0], b1_0 = ptrbb[1], b2_0 = ptrbb[2], b3_0 = ptrbb[3];
    float b0_1 = ptrbb[4], b1_1 = ptrbb[5], b2_1 = ptrbb[6], b3_1 = ptrbb[7];

    // First iteration unrolled
    a0 = ptrba[0];
    res0_0 += a0 * b0_0;
    res1_0 += a0 * b1_0;
    res2_0 += a0 * b2_0;
    res3_0 += a0 * b3_0;
    a1 = ptrba[1];
    res0_1 += a1 * b0_0;
    res1_1 += a1 * b1_0;
    res2_1 += a1 * b2_0;
    res3_1 += a1 * b3_0;
    a0 = ptrba[2];
    res0_2 += a0 * b0_0;
    res1_2 += a0 * b1_0;
    res2_2 += a0 * b2_0;
    res3_2 += a0 * b3_0;
    a1 = ptrba[3];
    res0_3 += a1 * b0_0;
    res1_3 += a1 * b1_0;
    res2_3 += a1 * b2_0;
    res3_3 += a1 * b3_0;
    a0 = ptrba[4];
    res0_4 += a0 * b0_0;
    res1_4 += a0 * b1_0;
    res2_4 += a0 * b2_0;
    res3_4 += a0 * b3_0;
    a1 = ptrba[5];
    res0_5 += a1 * b0_0;
    res1_5 += a1 * b1_0;
    res2_5 += a1 * b2_0;
    res3_5 += a1 * b3_0;
    a0 = ptrba[6];
    res0_6 += a0 * b0_0;
    res1_6 += a0 * b1_0;
    res2_6 += a0 * b2_0;
    res3_6 += a0 * b3_0;
    a1 = ptrba[7];
    res0_7 += a1 * b0_0;
    res1_7 += a1 * b1_0;
    res2_7 += a1 * b2_0;
    res3_7 += a1 * b3_0;

    // Second iteration using second set of b values
    a0 = ptrba[8];
    res0_0 += a0 * b0_1;
    res1_0 += a0 * b1_1;
    res2_0 += a0 * b2_1;
    res3_0 += a0 * b3_1;
    a1 = ptrba[9];
    res0_1 += a1 * b0_1;
    res1_1 += a1 * b1_1;
    res2_1 += a1 * b2_1;
    res3_1 += a1 * b3_1;
    a0 = ptrba[10];
    res0_2 += a0 * b0_1;
    res1_2 += a0 * b1_1;
    res2_2 += a0 * b2_1;
    res3_2 += a0 * b3_1;
    a1 = ptrba[11];
    res0_3 += a1 * b0_1;
    res1_3 += a1 * b1_1;
    res2_3 += a1 * b2_1;
    res3_3 += a1 * b3_1;
    a0 = ptrba[12];
    res0_4 += a0 * b0_1;
    res1_4 += a0 * b1_1;
    res2_4 += a0 * b2_1;
    res3_4 += a0 * b3_1;
    a1 = ptrba[13];
    res0_5 += a1 * b0_1;
    res1_5 += a1 * b1_1;
    res2_5 += a1 * b2_1;
    res3_5 += a1 * b3_1;
    a0 = ptrba[14];
    res0_6 += a0 * b0_1;
    res1_6 += a0 * b1_1;
    res2_6 += a0 * b2_1;
    res3_6 += a0 * b3_1;
    a1 = ptrba[15];
    res0_7 += a1 * b0_1;
    res1_7 += a1 * b1_1;
    res2_7 += a1 * b2_1;
    res3_7 += a1 * b3_1;

    ptrba = ptrba + 16;
    ptrbb = ptrbb + 8;
}
}
