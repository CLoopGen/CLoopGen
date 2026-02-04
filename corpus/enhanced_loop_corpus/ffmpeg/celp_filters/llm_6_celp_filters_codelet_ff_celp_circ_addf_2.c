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
    float temp;
    for (; k < n; k++) {
        temp = in[k] + fac * lagged[k - lag];
        out[k] = temp;
    }
}
