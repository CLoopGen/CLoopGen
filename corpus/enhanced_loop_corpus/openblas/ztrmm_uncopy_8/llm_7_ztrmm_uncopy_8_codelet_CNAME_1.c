#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;
extern float *ao2;
extern float *ao3;
extern float *ao4;
extern float *ao5;
extern float *ao6;
extern float *ao7;
extern float *ao8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: unroll by factor of 4 but reduce memory writes per iteration
// Simulate lighter work per loop instance with fewer operations

BLASLONG stride = 4;
for (ii = 0; ii < i; ii += stride) {
    BLASLONG remaining = i - ii;
    BLASLONG step = (remaining >= 4) ? 4 : remaining;

    if (step >= 1) {
        b[0] = ao1[0];
        b[1] = ao1[1];
        b[2] = ao2[0];
        b[3] = ao2[1];
        ao1 += 2; ao2 += 2;
        b += 4;
    }
    if (step >= 2) {
        b[0] = ao3[0];
        b[1] = ao3[1];
        b[2] = ao4[0];
        b[3] = ao4[1];
        ao3 += 2; ao4 += 2;
        b += 4;
    }
    if (step >= 3) {
        b[0] = ao5[0];
        b[1] = ao5[1];
        b[2] = ao6[0];
        b[3] = ao6[1];
        ao5 += 2; ao6 += 2;
        b += 4;
    }
    if (step >= 4) {
        b[0] = ao7[0];
        b[1] = ao7[1];
        b[2] = ao8[0];
        b[3] = ao8[1];
        ao7 += 2; ao8 += 2;
        b += 4;
    }
}
}
