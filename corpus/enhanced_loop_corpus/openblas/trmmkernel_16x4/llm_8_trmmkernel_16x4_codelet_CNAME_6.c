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
for (k = 0; k < temp; k += 2) {
    if (k + 1 < temp) {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        a0 = ptrba[0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;

        float a1 = ptrba[1];
        float b2 = ptrbb[2];
        float b3 = ptrbb[3];
        res0_0 += a1 * b2;
        res1_0 += a1 * b3;

        ptrba = ptrba + 2;
        ptrbb = ptrbb + 4;
    } else {
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        a0 = ptrba[0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;
        ptrba = ptrba + 1;
        ptrbb = ptrbb + 2;
    }
}
}
