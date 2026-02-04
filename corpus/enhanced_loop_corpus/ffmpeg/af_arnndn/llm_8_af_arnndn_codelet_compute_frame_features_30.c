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
    for (int i = 0; i < 12; i += 2) {
        int idx = i / 2;
        float c0 = ceps_0[idx];
        float c1 = ceps_1[idx];
        float c2 = ceps_2[idx];
        features[idx] = c0 + c1 + c2;
        features[22 + idx] = c0 - c2;
        features[28 + idx] = c0 - 2.0f * c1 + c2;
    }
}
