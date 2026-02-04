#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – process array from end to start
    for (int i = 3; i >= 0; i--) {
        coeffs[i] /= sum;
    }
}
