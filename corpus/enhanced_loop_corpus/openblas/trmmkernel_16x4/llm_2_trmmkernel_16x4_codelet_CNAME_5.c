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
for (k = 0; k < temp; k++) {
    BLASLONG idx = k * 2;
    b0 = ptrbb[idx];
    b1 = ptrbb[idx + 1];
    a0 = ptrba[idx];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    a1 = ptrba[idx + 1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
}
}
