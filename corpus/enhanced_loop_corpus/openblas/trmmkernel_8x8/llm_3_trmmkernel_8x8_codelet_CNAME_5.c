#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res1_0;
extern float res1_1;
extern float res2_0;
extern float res2_1;
extern float res3_0;
extern float res3_1;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride_bb = 4;
BLASLONG stride_ba = 2;
float *temp_ptrba = ptrba;
float *temp_ptrbb = ptrbb;

for (k = 0; k < temp; k++) {
    b0 = temp_ptrbb[0];
    b1 = temp_ptrbb[1];
    b2 = temp_ptrbb[2];
    b3 = temp_ptrbb[3];
    a0 = temp_ptrba[0];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    res2_0 += a0 * b2;
    res3_0 += a0 * b3;
    a1 = temp_ptrba[1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
    res2_1 += a1 * b2;
    res3_1 += a1 * b3;
    temp_ptrba += stride_ba;
    temp_ptrbb += stride_bb;
}
}
