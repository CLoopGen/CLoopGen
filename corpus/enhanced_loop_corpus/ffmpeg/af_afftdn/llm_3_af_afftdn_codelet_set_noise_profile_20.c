#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse array from last to first
    for (int m = 14; m >= 0; m--) {
        temp[m] = sample_noise[m];
    }
}
