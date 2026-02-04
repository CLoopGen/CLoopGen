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
for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    a0 = ptrba[0];
    a1 = ptrba[1];

    // Introduce temporary accumulators to modify data dependencies
    float t0_0 = a0 * b0;
    float t1_0 = a0 * b1;
    float t0_1 = a1 * b0;
    float t1_1 = a1 * b1;

    // Delayed accumulation to break direct RAW dependency on resX_Y
    res0_0 += t0_0;
    res1_0 += t1_0;
    res0_1 += t0_1;
    res1_1 += t1_1;

    a0 = ptrba[2];
    a1 = ptrba[3];

    float t0_2 = a0 * b0;
    float t1_2 = a0 * b1;
    float t0_3 = a1 * b0;
    float t1_3 = a1 * b1;

    res0_2 += t0_2;
    res1_2 += t1_2;
    res0_3 += t0_3;
    res1_3 += t1_3;

    ptrba = ptrba + 4;
    ptrbb = ptrbb + 2;
}
}
