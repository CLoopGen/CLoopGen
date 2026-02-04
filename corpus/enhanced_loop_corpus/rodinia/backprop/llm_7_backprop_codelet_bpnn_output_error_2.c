#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *delta;
extern float *target;
extern float *output;
extern int nj;
extern int j;
extern float o;
extern float t;
extern float errsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float acc_err = 0.0f;
    for (j = 1; j <= nj; j++) {
        o = output[j];
        t = target[j];
        delta[j] = o * (1. - o) * (t - o);
        float abs_delta = delta[j];
        acc_err += (abs_delta > 0.) ? abs_delta : -abs_delta;
    }
    errsum += acc_err;
}
