#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float tmp[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering and using a temporary array
    float temp_local[6];
    for (int i = 0; i < 6; i++) {
        temp_local[i] = tmp[i];
    }
    for (int i = 0; i < 6; i++) {
        features[22 + 12 + i] = temp_local[i];
    }
}
