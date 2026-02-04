#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float running_sum = sum;
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            coeffs[i] /= coeffs[i-1]; // Introduce RAW dependency on previous element
        } else {
            coeffs[i] /= running_sum;
        }
    }
}
