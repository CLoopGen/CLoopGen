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
    for (k = 0; k < lag; k += 2) {
        if (k + 1 < lag) {
            out[k] = in[k] + fac * lagged[n + k - lag] + fac * fac * lagged[n + k - lag] * lagged[n + k - lag];
            out[k+1] = in[k+1] + fac * lagged[n + k + 1 - lag] + fac * fac * lagged[n + k + 1 - lag] * lagged[n + k + 1 - lag];
        } else {
            out[k] = in[k] + fac * lagged[n + k - lag] + fac * fac * lagged[n + k - lag] * lagged[n + k - lag];
        }
    }
}
