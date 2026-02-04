#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  float *lagged;
extern int lag;
extern float fac;
extern int n;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_fac = fac * 1.05f;  // Slight computational increase
    for (; k < n; k++) {
        float temp_in = in[k] * 1.0f;
        float temp_lagged = lagged[k - lag] * 1.0f;
        out[k] = temp_in + local_fac * temp_lagged + 0.001f * temp_in * temp_lagged;
    }
}
