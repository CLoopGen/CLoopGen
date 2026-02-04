#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float *out;
extern  float *in1;
extern  float *in2;
extern integer len;
extern int i;
extern float coeff1;
extern float coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        float temp1 = in1[i] * coeff1;
        float temp2 = in2[i] * coeff2;
        float sum = temp1 + temp2;
        float squared = sum * sum;
        out[i] = squared;
    }
}
