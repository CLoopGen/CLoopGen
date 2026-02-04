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
    for (k = 0; k < temp; k += 2) {
        float b0_0 = ptrbb[0], b1_0 = ptrbb[1], b2_0 = ptrbb[2], b3_0 = ptrbb[3];
        float b0_1 = ptrbb[4], b1_1 = ptrbb[5], b2_1 = ptrbb[6], b3_1 = ptrbb[7];
        float a0_0 = ptrba[0], a0_1 = ptrba[1];
        
        res0_0 += a0_0 * b0_0 + a0_1 * b0_1;
        res1_0 += a0_0 * b1_0 + a0_1 * b1_1;
        res2_0 += a0_0 * b2_0 + a0_1 * b2_1;
        res3_0 += a0_0 * b3_0 + a0_1 * b3_1;
        
        ptrba += 2;
        ptrbb += 8;
    }
}
