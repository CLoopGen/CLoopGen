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
    float local_res0 = res0_0;
    float local_res1 = res1_0;
    float a_val;
    for (k = 0; k < temp; k++) {
        a_val = ptrba[0];
        local_res0 += a_val * ptrbb[0];
        local_res1 += a_val * ptrbb[1];
        ptrba = ptrba + 1;
        ptrbb = ptrbb + 2;
    }
    res0_0 = local_res0;
    res1_0 = local_res1;
}
