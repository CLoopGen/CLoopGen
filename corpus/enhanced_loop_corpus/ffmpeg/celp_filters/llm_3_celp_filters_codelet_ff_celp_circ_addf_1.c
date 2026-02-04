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
    // Variant 2: Reverse consecutive access – traverse arrays from end to start
    // Memory access pattern becomes descending: out[lag-1-k], in[lag-1-k], etc.
    for (k = 0; k < lag; k++) {
        int rev_k = lag - 1 - k;
        out[rev_k] = in[rev_k] + fac * lagged[n + rev_k - lag];
    }
}
