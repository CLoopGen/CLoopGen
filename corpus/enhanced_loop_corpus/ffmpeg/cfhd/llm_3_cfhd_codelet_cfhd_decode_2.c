#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int16_t *coeff_data;
extern int run;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t indices[] = {0, 2, 4, 6, 8}; // Example strided index pattern
    int stride = 5; // Number of elements in indices
    int full_blocks = run / stride;
    int remainder = run % stride;

    for (i = 0; i < full_blocks; i++) {
        for (int j = 0; j < stride; j++) {
            coeff_data[i * stride + indices[j]] = coeff;
        }
    }

    for (i = 0; i < remainder; i++) {
        coeff_data[full_blocks * stride + indices[i]] = coeff;
    }
}
