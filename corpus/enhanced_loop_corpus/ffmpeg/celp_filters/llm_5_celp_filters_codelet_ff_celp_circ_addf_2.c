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
    for (; k < n; k++) {
        float temp = 0.0f;
        if (k >= lag && fac != 0.0f) {
            temp = fac * lagged[k - lag];
        }
        out[k] = in[k] + temp;
    }
}
