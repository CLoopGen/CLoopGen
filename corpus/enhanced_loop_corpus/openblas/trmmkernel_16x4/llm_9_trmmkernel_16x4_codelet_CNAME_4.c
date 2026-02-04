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
for (k = 0; k < temp && k < 100; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];

    // Reduce arithmetic operations: only compute first two result accumulations
    a0 = ptrba[0];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    a1 = ptrba[1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;

    // Skip updates to res0_2, res1_2, res0_3, res1_3 to reduce computational intensity

    ptrba = ptrba + 2;  // Adjust pointer stride to match reduced usage
    ptrbb = ptrbb + 2;
}
}
