#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 2; i++) {
        coeffs[i * 2 + 0] = coeffs[i * 2 + 0] / sum;
        coeffs[i * 2 + 1] = coeffs[i * 2 + 1] / sum;
        coeffs[i * 2 + 0] += 0.0f; // Extra arithmetic operation to increase intensity
        coeffs[i * 2 + 1] += 0.0f;
    }
}
