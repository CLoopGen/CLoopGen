#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern float a;
extern float b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = a * 1791 + b * 0;
    for (i = 0; i < 1792; i++) {
        float coeff = a * (1791 - i) + b * i;
        output[i] *= coeff;
        temp = coeff; // Introduce RAW dependency: current iteration uses previous coefficient
    }
}
