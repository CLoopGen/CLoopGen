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
for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    b2 = ptrbb[2];
    b3 = ptrbb[3];
    a0 = ptrba[0];
    a1 = ptrba[1];

    // Introduce temporary accumulators to remove direct WAW dependencies on res* variables
    float t0_0 = a0 * b0;
    float t1_0 = a0 * b1;
    float t2_0 = a0 * b2;
    float t3_0 = a0 * b3;
    float t0_1 = a1 * b0;
    float t1_1 = a1 * b1;
    float t2_1 = a1 * b2;
    float t3_1 = a1 * b3;

    // Accumulate into results only once per iteration to reduce WAW hazards
    res0_0 += t0_0;
    res1_0 += t1_0;
    res2_0 += t2_0;
    res3_0 += t3_0;
    res0_1 += t0_1;
    res1_1 += t1_1;
    res2_1 += t2_1;
    res3_1 += t3_1;

    ptrba = ptrba + 2;
    ptrbb = ptrbb + 4;
}
}
