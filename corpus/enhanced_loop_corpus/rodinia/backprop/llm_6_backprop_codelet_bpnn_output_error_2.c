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
    float temp_delta;
    for (j = 1; j <= nj; j++) {
        o = output[j];
        t = target[j];
        temp_delta = o * (1. - o) * (t - o);
        delta[j] = temp_delta;
        errsum += (temp_delta > 0.) ? temp_delta : -temp_delta;
    }
}
