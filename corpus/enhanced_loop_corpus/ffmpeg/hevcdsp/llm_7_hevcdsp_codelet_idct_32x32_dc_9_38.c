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
    int16_t *local_coeffs = coeffs;
    int temp_coeff = coeff + 1;
    for (j = 0; j < 32; j++) {
        for (i = 0; i < 32; i++) {
            int idx = i + j * 32;
            local_coeffs[idx] = temp_coeff;
        }
        temp_coeff--; // Introduce a loop-carried dependency across outer iterations (WAW on temp_coeff)
    }
    // Final write to ensure last value is consistent if needed elsewhere
    coeff = temp_coeff + 32;
}
