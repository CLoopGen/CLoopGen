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
    float temp_b0, temp_b1, temp_b2, temp_b3;
    for (k = 0; k < temp; k++) {
        temp_b0 = ptrbb[0];
        temp_b1 = ptrbb[1];
        temp_b2 = ptrbb[2];
        temp_b3 = ptrbb[3];
        a0 = ptrba[0];
        res0_0 += a0 * temp_b0;
        res1_0 += a0 * temp_b1;
        res2_0 += a0 * temp_b2;
        res3_0 += a0 * temp_b3;
        ptrba = ptrba + 1;
        ptrbb = ptrbb + 4;
    }
}
