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
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride_ba = 8;
BLASLONG stride_bb = 4;
for (k = 0; k < temp; k++) {
    BLASLONG offset_ba = k * stride_ba;
    BLASLONG offset_bb = k * stride_bb;
    b0 = ((float*)ptrba)[offset_ba / sizeof(float)];
    b1 = ((float*)ptrba)[offset_ba / sizeof(float) + 2];
    a0 = ((float*)ptrbb)[offset_bb / sizeof(float)];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    a1 = ((float*)ptrbb)[offset_bb / sizeof(float) + 1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
    a0 = ((float*)ptrbb)[offset_bb / sizeof(float) + 2];
    res0_2 += a0 * b0;
    res1_2 += a0 * b1;
    a1 = ((float*)ptrbb)[offset_bb / sizeof(float) + 3];
    res0_3 += a1 * b0;
    res1_3 += a1 * b1;
}
}
