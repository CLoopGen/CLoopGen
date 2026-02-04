#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_val = 0;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            int idx = i + j * 4;
            coeffs[idx] = coeff + prev_val; // Introduce RAW dependency: current write depends on previous value
            prev_val = coeffs[idx]; // Create loop-carried dependency across iterations
        }
    }
}
