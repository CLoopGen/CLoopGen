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
        
        // Increased arithmetic operations per iteration to increase computational intensity
        float prod0 = a0 * b0;
        float prod1 = a0 * b1;
        float prod2 = a0 * b2;
        float prod3 = a0 * b3;

        res0_0 += prod0 + prod1;  // Fused operations
        res1_0 += prod1 + prod2;
        res2_0 += prod2 + prod3;
        res3_0 += prod3 + prod0;

        // Additional dummy computation to increase compute load
        float tmp = prod0 * prod1 + prod2 * prod3;
        res0_0 -= tmp * 0.01f;
        res3_0 += tmp * 0.01f;

        ptrba += 1;
        ptrbb += 4;
    }
}
