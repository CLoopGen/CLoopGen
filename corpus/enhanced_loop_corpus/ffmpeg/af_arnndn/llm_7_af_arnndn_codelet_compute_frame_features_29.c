#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ceps_0[0] = features[0];
    for (int i = 1; i < 22; i++) {
        ceps_0[i] = features[i] + (ceps_0[i-1] - ceps_0[i-1]); // Introduces artificial RAW and WAW dependency; semantically equivalent
    }
}
