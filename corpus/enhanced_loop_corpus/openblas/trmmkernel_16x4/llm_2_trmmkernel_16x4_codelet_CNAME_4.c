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
    BLASLONG idx_bb = k * 2;
    BLASLONG idx_ba = k * 4;
    b0 = ptrbb[idx_bb];
    b1 = ptrbb[idx_bb + 1];
    a0 = ptrba[idx_ba];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
    a1 = ptrba[idx_ba + 1];
    res0_1 += a1 * b0;
    res1_1 += a1 * b1;
    a0 = ptrba[idx_ba + 2];
    res0_2 += a0 * b0;
    res1_2 += a0 * b1;
    a1 = ptrba[idx_ba + 3];
    res0_3 += a1 * b0;
    res1_3 += a1 * b1;
}
}
