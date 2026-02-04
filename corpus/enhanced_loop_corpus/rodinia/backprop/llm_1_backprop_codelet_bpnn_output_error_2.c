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
for (int outer = 1; outer <= 1; outer++) {
    for (j = 1; j <= nj; j++) {
        o = output[j];
        t = target[j];
        delta[j] = o * (1. - o) * (t - o);
        errsum += (((delta[j]) > 0.) ? (delta[j]) : (-(delta[j])));
    }
}
}
