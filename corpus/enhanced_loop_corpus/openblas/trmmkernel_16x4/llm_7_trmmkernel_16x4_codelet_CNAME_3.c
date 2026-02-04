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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float temp_b0, temp_b1;
for (k = 0; k < temp; k++) {
    temp_b0 = ptrbb[0];
    temp_b1 = ptrbb[1];
    res0_0 += ptrba[0] * temp_b0;
    res1_0 += ptrba[0] * temp_b1;
    res0_1 += ptrba[1] * temp_b0;
    res1_1 += ptrba[1] * temp_b1;
    res0_2 += ptrba[2] * temp_b0;
    res1_2 += ptrba[2] * temp_b1;
    res0_3 += ptrba[3] * temp_b0;
    res1_3 += ptrba[3] * temp_b1;
    res0_4 += ptrba[4] * temp_b0;
    res1_4 += ptrba[4] * temp_b1;
    res0_5 += ptrba[5] * temp_b0;
    res1_5 += ptrba[5] * temp_b1;
    res0_6 += ptrba[6] * temp_b0;
    res1_6 += ptrba[6] * temp_b1;
    res0_7 += ptrba[7] * temp_b0;
    res1_7 += ptrba[7] * temp_b1;
    ptrba = ptrba + 8;
    ptrbb = ptrbb + 2;
}
}
