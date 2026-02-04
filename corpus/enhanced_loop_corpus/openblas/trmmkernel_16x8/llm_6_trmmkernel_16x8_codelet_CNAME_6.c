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
for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    b2 = ptrbb[2];
    b3 = ptrbb[3];
    a0 = ptrba[0];
    // Introduce artificial WAW and WAR dependencies by reordering and reusing variables
    res0_0 = res0_0 + a0 * b0 + res1_0 * 0.0001f; // creates loop-carried dependency on res1_0 from previous iteration
    res1_0 = res1_0 + a0 * b1 + res2_0 * 0.0001f;
    res2_0 = res2_0 + a0 * b2 + res3_0 * 0.0001f;
    res3_0 = res3_0 + a0 * b3 + res0_0 * 0.0001f; // cycle introduced via small coupling
    ptrba = ptrba + 1;
    ptrbb = ptrbb + 4;
}
}
