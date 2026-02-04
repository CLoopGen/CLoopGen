#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float temp_res0_0 = res0_0, temp_res0_1 = res0_1, temp_res0_2 = res0_2, temp_res0_3 = res0_3;
float temp_res1_0 = res1_0, temp_res1_1 = res1_1, temp_res1_2 = res1_2, temp_res1_3 = res1_3;
float temp_res2_0 = res2_0, temp_res2_1 = res2_1, temp_res2_2 = res2_2, temp_res2_3 = res2_3;
float temp_res3_0 = res3_0, temp_res3_1 = res3_1, temp_res3_2 = res3_2, temp_res3_3 = res3_3;

for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    b2 = ptrbb[2];
    b3 = ptrbb[3];

    a0 = ptrba[0];
    temp_res0_0 += a0 * b0;
    temp_res1_0 += a0 * b1;
    temp_res2_0 += a0 * b2;
    temp_res3_0 += a0 * b3;

    a1 = ptrba[1];
    temp_res0_1 += a1 * b0;
    temp_res1_1 += a1 * b1;
    temp_res2_1 += a1 * b2;
    temp_res3_1 += a1 * b3;

    a0 = ptrba[2];
    temp_res0_2 += a0 * b0;
    temp_res1_2 += a0 * b1;
    temp_res2_2 += a0 * b2;
    temp_res3_2 += a0 * b3;

    a1 = ptrba[3];
    temp_res0_3 += a1 * b0;
    temp_res1_3 += a1 * b1;
    temp_res2_3 += a1 * b2;
    temp_res3_3 += a1 * b3;

    ptrba = ptrba + 4;
    ptrbb = ptrbb + 4;
}

res0_0 = temp_res0_0; res0_1 = temp_res0_1; res0_2 = temp_res0_2; res0_3 = temp_res0_3;
res1_0 = temp_res1_0; res1_1 = temp_res1_1; res1_2 = temp_res1_2; res1_3 = temp_res1_3;
res2_0 = temp_res2_0; res2_1 = temp_res2_1; res2_2 = temp_res2_2; res2_3 = temp_res2_3;
res3_0 = temp_res3_0; res3_1 = temp_res3_1; res3_2 = temp_res3_2; res3_3 = temp_res3_3;
}
