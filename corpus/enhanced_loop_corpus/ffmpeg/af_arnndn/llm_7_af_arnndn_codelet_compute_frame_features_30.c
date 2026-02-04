#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;
extern float *ceps_1;
extern float *ceps_2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float accum = 0.0f;
    for (int i = 0; i < 6; i++) {
        accum += ceps_0[i];
        features[i] = accum + ceps_1[i] + ceps_2[i];
        features[22 + i] = accum - ceps_2[i];
        features[28 + i] = accum - 2 * ceps_1[i] + ceps_2[i];
    }
}
