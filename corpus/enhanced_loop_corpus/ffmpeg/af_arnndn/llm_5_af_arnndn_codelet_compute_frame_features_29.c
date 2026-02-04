#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 22; i++) {
        if (!(i & 1)) { // Only copy even-indexed elements
            ceps_0[i] = features[i];
        } else {
            ceps_0[i] = 0.0f; // Set odd indices to zero instead
        }
    }
}
