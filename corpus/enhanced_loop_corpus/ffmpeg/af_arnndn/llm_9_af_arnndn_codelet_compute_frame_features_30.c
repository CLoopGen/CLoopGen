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
    for (int i = 0; i < 3; i++) {
        float c0_0 = ceps_0[i];
        float c1_0 = ceps_1[i];
        float c2_0 = ceps_2[i];
        float c0_1 = ceps_0[i + 3];
        float c1_1 = ceps_1[i + 3];
        float c2_1 = ceps_2[i + 3];

        features[i] = c0_0 + c1_0 + c2_0;
        features[i + 3] = c0_1 + c1_1 + c2_1;

        features[22 + i] = c0_0 - c2_0;
        features[22 + i + 3] = c0_1 - c2_1;

        features[28 + i] = c0_0 - 2.0f * c1_0 + c2_0;
        features[28 + i + 3] = c0_1 - 2.0f * c1_1 + c2_1;
    }
}
