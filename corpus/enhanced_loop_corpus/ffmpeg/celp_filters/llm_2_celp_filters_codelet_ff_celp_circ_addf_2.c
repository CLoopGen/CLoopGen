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
    // Variant 1: Strided memory access (stride of 2)
    // This variant processes every second element, which changes the memory access pattern to strided
    for (int k = 0; k < n; k += 2)
        out[k] = in[k] + fac * lagged[k - lag];
}
