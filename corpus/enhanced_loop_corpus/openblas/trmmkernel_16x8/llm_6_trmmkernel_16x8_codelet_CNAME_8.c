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
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    a0 = ptrba[0];
    a1 = ptrba[1];
    float t0 = a0 * b0, t1 = a0 * b1;
    float t2 = a1 * b0, t3 = a1 * b1;
    res0_0 += t0;
    res1_0 += t1;
    res0_1 += t2;
    res1_1 += t3;
    a0 = ptrba[2];
    a1 = ptrba[3];
    t0 = a0 * b0; t1 = a0 * b1;
    t2 = a1 * b0; t3 = a1 * b1;
    res0_2 += t0;
    res1_2 += t1;
    res0_3 += t2;
    res1_3 += t3;
    a0 = ptrba[4];
    a1 = ptrba[5];
    t0 = a0 * b0; t1 = a0 * b1;
    t2 = a1 * b0; t3 = a1 * b1;
    res0_4 += t0;
    res1_4 += t1;
    res0_5 += t2;
    res1_5 += t3;
    a0 = ptrba[6];
    a1 = ptrba[7];
    t0 = a0 * b0; t1 = a0 * b1;
    t2 = a1 * b0; t3 = a1 * b1;
    res0_6 += t0;
    res1_6 += t1;
    res0_7 += t2;
    res1_7 += t3;
    ptrba = ptrba + 8;
    ptrbb = ptrbb + 2;
}
}
