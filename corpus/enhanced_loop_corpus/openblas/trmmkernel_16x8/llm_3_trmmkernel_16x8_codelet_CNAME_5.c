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
BLASLONG stride_a = 2;
BLASLONG stride_b = 4;
for (k = 0; k < temp; k++) {
    BLASLONG index_a = k * stride_a;
    BLASLONG index_b = k * stride_b;
    b0 = ptrbb[index_b + 0];
    b1 = ptrbb[index_b + 1];
    b2 = ptrbb[index_b + 2];
    b3 = ptrbb[index_b + 3];
    a0 = ptrba[index_a + 0];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    res2_0 += a0 * b2;
    res3_0 += a0 * b3;
    a1 = ptrba[index_a + 1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
    res2_1 += a1 * b2;
    res3_1 += a1 * b3;
}
}
