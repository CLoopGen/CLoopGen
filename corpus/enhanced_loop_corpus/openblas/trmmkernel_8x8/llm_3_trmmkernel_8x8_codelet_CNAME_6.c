#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res1_0;
extern float res2_0;
extern float res3_0;
extern float a0;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG idx_a = 0;
BLASLONG idx_b = 0;
for (k = 0; k < temp; k++) {
    b0 = ptrbb[idx_b];
    b1 = ptrbb[idx_b + 1];
    b2 = ptrbb[idx_b + 2];
    b3 = ptrbb[idx_b + 3];
    a0 = ptrba[idx_a];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    res2_0 += a0 * b2;
    res3_0 += a0 * b3;
    idx_a += 1;
    idx_b += 4;
}
}
