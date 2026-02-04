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
    float temp_i0f, temp_i1f, temp_i2f;
    for (i = 0; i < csize; i++) {
        temp_i0f = *src0 + (f_ict_params[0] * *src2);
        temp_i1f = *src0 - (f_ict_params[1] * *src1) - (f_ict_params[2] * *src2);
        temp_i2f = *src0 + (f_ict_params[3] * *src1);
        *src0++ = temp_i0f;
        *src1++ = temp_i1f;
        *src2++ = temp_i2f;
    }
}
