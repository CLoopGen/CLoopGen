#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float *out;
extern  float *in;
extern integer len;
extern int i;
extern float coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float c_sq = coeff * coeff;
    for (i = 0; i < len; i++) {
        float temp = in[i] * in[i];
        out[i] = c_sq * temp + coeff * in[i];
    }
}
