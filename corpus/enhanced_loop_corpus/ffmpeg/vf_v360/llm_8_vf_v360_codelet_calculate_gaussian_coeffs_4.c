#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = sum * sum;
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            coeffs[i] = coeffs[i] / temp_sum + coeffs[i] / sum;
        }
    }
}
