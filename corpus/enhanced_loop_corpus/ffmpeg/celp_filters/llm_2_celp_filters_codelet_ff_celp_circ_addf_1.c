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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: out[2*k], in[2*k], lagged[n + 2*k - lag]
    // Ensures k iterates only up to lag/2 to stay within bounds
    int limit = lag / 2;
    for (k = 0; k < limit; k++) {
        int idx = 2 * k;
        out[idx]     = in[idx] + fac * lagged[n + idx - lag];
        out[idx + 1] = in[idx + 1] + fac * lagged[n + idx + 1 - lag];
    }
    // Handle odd lag case
    if (lag % 2 == 1) {
        out[lag - 1] = in[lag - 1] + fac * lagged[n - 1];
    }
}
