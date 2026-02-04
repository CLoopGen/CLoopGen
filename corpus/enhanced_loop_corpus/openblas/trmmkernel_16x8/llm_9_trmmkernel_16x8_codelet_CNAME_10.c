#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res1_0;
extern float res1_1;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: only accumulate one product per iteration
// Trip count remains same, but work per iteration is reduced
for (k = 0; k < temp; k++) {
    a0 = ptrba[0];
    b0 = ptrbb[0];
    res0_0 += a0 * b0;  // Only one multiply-add instead of four

    ptrba++;
    ptrbb++;
}
}
