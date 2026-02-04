#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 44; i += 2) {
        ceps_0[i] = features[i];
        if (i + 1 < 22) {
            ceps_0[i + 1] = features[i + 1];
        }
    }
}
