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
float temp_res0 = res0_0;
float temp_res1 = res1_0;
float temp_res2 = res2_0;
float temp_res3 = res3_0;
// Remove loop-carried dependencies by using local accumulators
for (k = 0; k < temp; k++) {
    b0 = ptrbb[0];
    b1 = ptrbb[1];
    b2 = ptrbb[2];
    b3 = ptrbb[3];
    a0 = ptrba[0];
    // Eliminate RAW hazards across iterations by deferring write to global res*
    temp_res0 += a0 * b0;
    temp_res1 += a0 * b1;
    temp_res2 += a0 * b2;
    temp_res3 += a0 * b3;
    ptrba = ptrba + 1;
    ptrbb = ptrbb + 4;
}
// Write accumulated results back after loop (no loop-carried dependency)
res0_0 = temp_res0;
res1_0 = temp_res1;
res2_0 = temp_res2;
res3_0 = temp_res3;
}
