#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float f_ict_params[4];
extern int csize;
extern float *src0;
extern float *src1;
extern float *src2;
extern float i0f;
extern float i1f;
extern float i2f;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced computational intensity: fewer arithmetic operations and simplified expressions
    for (i = 0; i < csize; i++) {
        i0f = *src0 + f_ict_params[0] * *src2;
        i1f = *src0 - f_ict_params[1] * *src1;  // Removed one multiplication-addition term
        i2f = *src1;                             // Simplified: just copy *src1 instead of computing
        *src0++ = i0f;
        *src1++ = i1f;
        *src2++ = i2f;
    }
}
