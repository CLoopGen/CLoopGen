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
int k1;
for (k1 = 0; k1 < n; k1++) {
    for (k = k1; k < k1 + 1 && k < n; k++)
        out[k] = in[k] + fac * lagged[k - lag];
}
}
