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
    int k1, k2;
    for (k1 = 0; k1 < lag; k1++) {
        for (k2 = 0; k2 < 1; k2++) {
            out[k1] = in[k1] + fac * lagged[n + k1 - lag];
        }
    }
}
