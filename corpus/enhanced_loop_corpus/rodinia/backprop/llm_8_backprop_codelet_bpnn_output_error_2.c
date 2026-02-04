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
for (j = 1; j <= nj; j += 2) {
    o = output[j];
    t = target[j];
    delta[j] = o * (1. - o) * (t - o);
    errsum += ((delta[j]) > 0.) ? (delta[j]) : (-(delta[j]));
    if (j + 1 <= nj) {
        o = output[j + 1];
        t = target[j + 1];
        delta[j + 1] = o * (1. - o) * (t - o);
        errsum += ((delta[j + 1]) > 0.) ? (delta[j + 1]) : (-(delta[j + 1]));
    }
}
}
