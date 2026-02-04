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
for (k = 0; k < temp; k += 2) {
    if (k + 1 < temp) {
        // Process two iterations at once to increase computational intensity
        float b0_0 = ptrbb[0], b1_0 = ptrbb[1];
        float a0_0 = ptrba[0];
        res0_0 += a0_0 * b0_0;
        res1_0 += a0_0 * b1_0;
        float a1_0 = ptrba[1];
        res0_1 += a1_0 * b0_0;
        res1_1 += a1_0 * b1_0;

        float b0_1 = ptrbb[2], b1_1 = ptrbb[3];
        float a0_1 = ptrba[2];
        res0_0 += a0_1 * b0_1;
        res1_0 += a0_1 * b1_1;
        float a1_1 = ptrba[3];
        res0_1 += a1_1 * b0_1;
        res1_1 += a1_1 * b1_1;

        ptrba += 4;
        ptrbb += 4;
    } else {
        // Handle leftover iteration
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        a0 = ptrba[0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;
        a1 = ptrba[1];
        res0_1 += a1 * b0;
        res1_1 += a1 * b1;
        ptrba += 2;
        ptrbb += 2;
    }
}
}
