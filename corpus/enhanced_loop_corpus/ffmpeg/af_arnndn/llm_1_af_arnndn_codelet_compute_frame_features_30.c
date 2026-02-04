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
        for (int k = 0; k < 2; k++) {
            int idx = i * 2 + k;
            if (idx < 6) {
                features[idx] = ceps_0[idx] + ceps_1[idx] + ceps_2[idx];
                features[22 + idx] = ceps_0[idx] - ceps_2[idx];
                features[22 + 6 + idx] = ceps_0[idx] - 2 * ceps_1[idx] + ceps_2[idx];
            }
        }
    }
}
