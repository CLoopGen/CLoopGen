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
    for (; k < n - 1; k += 2) {
        out[k]     = in[k] + fac * lagged[k - lag];
        out[k + 1] = in[k + 1] + fac * lagged[k + 1 - lag];
    }
    if (k < n) {
        out[k] = in[k] + fac * lagged[k - lag];
    }
}
