#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_coeffs[4];
    for (int i = 0; i < 4; i++) {
        local_coeffs[i] = coeffs[i] / sum; // Remove write-to-shared memory, eliminate RAW on coeffs
    }
    for (int i = 0; i < 4; i++) {
        coeffs[i] = local_coeffs[i]; // Decouple read and write phases: no loop-carried dependencies
    }
}
