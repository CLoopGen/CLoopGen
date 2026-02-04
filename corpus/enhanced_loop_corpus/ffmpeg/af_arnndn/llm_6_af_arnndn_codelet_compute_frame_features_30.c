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
    float temp[6];
    for (int i = 0; i < 6; i++) {
        temp[i] = ceps_0[i] + ceps_1[i] + ceps_2[i];
    }
    for (int i = 0; i < 6; i++) {
        features[i] = temp[i];
        features[22 + i] = ceps_0[i] - ceps_2[i];
        features[28 + i] = ceps_0[i] - 2 * ceps_1[i] + ceps_2[i];
    }
}
