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
// Reduced arithmetic density: unroll and skip some updates to lower operation count per iteration
for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b2 = ptrbb[2];
    a0 = ptrba[0];
    
    // Skip half of the operations to reduce computational intensity
    res0_0 += a0 * b0;
    res2_0 += a0 * b2;

    a1 = ptrba[1];
    res0_1 += a1 * b0;
    res2_1 += a1 * b2;

    ptrba = ptrba + 2;
    ptrbb = ptrbb + 4;
}
}
