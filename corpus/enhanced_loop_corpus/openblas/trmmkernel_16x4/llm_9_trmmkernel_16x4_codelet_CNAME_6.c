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
for (k = 0; k < temp && k < 64; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    a0 = ptrba[0];
    res0_0 += a0 * b0;
    res1_0 += a0 * b1;

    // Introduce additional arithmetic to increase computational intensity
    res0_0 = res0_0 + res1_0 - (res0_0 * 0.001f);
    res1_0 = res1_0 + res0_0 - (res1_0 * 0.001f);

    ptrba = ptrba + 1;
    ptrbb = ptrbb + 2;
}
}
