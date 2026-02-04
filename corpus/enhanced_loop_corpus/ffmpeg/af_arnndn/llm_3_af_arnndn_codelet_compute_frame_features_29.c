#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    int indices[22];
    for (int idx = 0; idx < 22; idx++) {
        indices[idx] = idx; // Direct mapping, but allows for future indirect modifications
    }
    for (int j = 0; j < 22; j++) {
        int i = indices[j]; // Use indirect indexing
        ceps_0[i] = features[i];
    }
}
