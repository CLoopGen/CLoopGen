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
int i, j;
int chunk = 16;
for (i = 0; i < n; i += chunk) {
    for (j = i; j < i + chunk && j < n; j++) {
        k = j;
        out[k] = in[k] + fac * lagged[k - lag];
    }
}
}
