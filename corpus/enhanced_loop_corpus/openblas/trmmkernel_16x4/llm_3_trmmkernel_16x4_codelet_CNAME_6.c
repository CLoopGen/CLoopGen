#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res1_0;
extern float a0;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *ba_base = ptrba;
float *bb_base = ptrbb;
for (k = 0; k < temp; k++) {
    b0 = bb_base[2*k];
    b1 = bb_base[2*k + 1];
    a0 = ba_base[k];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;
}
ptrba = ba_base + temp;
ptrbb = bb_base + 2 * temp;
}
