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
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            features[i] = ceps_0[i] + ceps_1[i] + ceps_2[i];
        } else {
            features[i] = ceps_0[i];
        }
        features[22 + i] = ceps_0[i] - ceps_2[i];
        features[22 + 6 + i] = ceps_0[i] - 2 * ceps_1[i] + ceps_2[i];
    }
}
