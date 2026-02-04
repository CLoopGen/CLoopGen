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
for (k = 0; k < temp; k++) {
    b0 = ptrbb[k * 2 + 0];
    b1 = ptrbb[k * 2 + 1];
    a0 = ptrba[k * 8 + 0];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    a1 = ptrba[k * 8 + 1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
    a0 = ptrba[k * 8 + 2];
    res0_2 += a0 * b0;
    res1_2 += a0 * b1;
    a1 = ptrba[k * 8 + 3];
    res0_3 += a1 * b0;
    res1_3 += a1 * b1;
    a0 = ptrba[k * 8 + 4];
    res0_4 += a0 * b0;
    res1_4 += a0 * b1;
    a1 = ptrba[k * 8 + 5];
    res0_5 += a1 * b0;
    res1_5 += a1 * b1;
    a0 = ptrba[k * 8 + 6];
    res0_6 += a0 * b0;
    res1_6 += a0 * b1;
    a1 = ptrba[k * 8 + 7];
    res0_7 += a1 * b0;
    res1_7 += a1 * b1;
}
}
