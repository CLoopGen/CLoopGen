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
extern float res2_0;
extern float res2_1;
extern float res2_2;
extern float res2_3;
extern float res3_0;
extern float res3_1;
extern float res3_2;
extern float res3_3;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern float b2;
extern float b3;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < temp; k += 2) {
    if (k + 1 < temp) {
        // Process two iterations per loop to increase computational intensity
        float b0_0 = ptrbb[0];
        float b1_0 = ptrbb[1];
        float b2_0 = ptrbb[2];
        float b3_0 = ptrbb[3];
        float a0_0 = ptrba[0];
        res0_0 += a0_0 * b0_0;
        res1_0 += a0_0 * b1_0;
        res2_0 += a0_0 * b2_0;
        res3_0 += a0_0 * b3_0;
        float a1_0 = ptrba[1];
        res0_1 += a1_0 * b0_0;
        res1_1 += a1_0 * b1_0;
        res2_1 += a1_0 * b2_0;
        res3_1 += a1_0 * b3_0;
        a0_0 = ptrba[2];
        res0_2 += a0_0 * b0_0;
        res1_2 += a0_0 * b1_0;
        res2_2 += a0_0 * b2_0;
        res3_2 += a0_0 * b3_0;
        a1_0 = ptrba[3];
        res0_3 += a1_0 * b0_0;
        res1_3 += a1_0 * b1_0;
        res2_3 += a1_0 * b2_0;
        res3_3 += a1_0 * b3_0;

        // Second iteration of the pair
        float b0_1 = ptrbb[4];
        float b1_1 = ptrbb[5];
        float b2_1 = ptrbb[6];
        float b3_1 = ptrbb[7];
        float a0_1 = ptrba[4];
        res0_0 += a0_1 * b0_1;
        res1_0 += a0_1 * b1_1;
        res2_0 += a0_1 * b2_1;
        res3_0 += a0_1 * b3_1;
        float a1_1 = ptrba[5];
        res0_1 += a1_1 * b0_1;
        res1_1 += a1_1 * b1_1;
        res2_1 += a1_1 * b2_1;
        res3_1 += a1_1 * b3_1;
        a0_1 = ptrba[6];
        res0_2 += a0_1 * b0_1;
        res1_2 += a0_1 * b1_1;
        res2_2 += a0_1 * b2_1;
        res3_2 += a0_1 * b3_1;
        a1_1 = ptrba[7];
        res0_3 += a1_1 * b0_1;
        res1_3 += a1_1 * b1_1;
        res2_3 += a1_1 * b2_1;
        res3_3 += a1_1 * b3_1;

        ptrba = ptrba + 8;
        ptrbb = ptrbb + 8;
    } else {
        // Handle leftover iteration
        b0 = ptrbb[0];
        b1 = ptrbb[1];
        b2 = ptrbb[2];
        b3 = ptrbb[3];
        a0 = ptrba[0];
        res0_0 += a0 * b0;
        res1_0 += a0 * b1;
        res2_0 += a0 * b2;
        res3_0 += a0 * b3;
        a1 = ptrba[1];
        res0_1 += a1 * b0;
        res1_1 += a1 * b1;
        res2_1 += a1 * b2;
        res3_1 += a1 * b3;
        a0 = ptrba[2];
        res0_2 += a0 * b0;
        res1_2 += a0 * b1;
        res2_2 += a0 * b2;
        res3_2 += a0 * b3;
        a1 = ptrba[3];
        res0_3 += a1 * b0;
        res1_3 += a1 * b1;
        res2_3 += a1 * b2;
        res3_3 += a1 * b3;
        ptrba = ptrba + 4;
        ptrbb = ptrbb + 4;
    }
}
}
