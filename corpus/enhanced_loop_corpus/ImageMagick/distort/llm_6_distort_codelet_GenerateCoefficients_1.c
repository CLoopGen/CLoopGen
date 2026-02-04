#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *coeff;
extern size_t i;
extern size_t number_coefficients;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < number_coefficients; j++) {
        coeff[j] = 0.0;
        if (j > 0)
            coeff[j] += coeff[j-1]; // Introduce RAW dependency: current depends on previous
    }
    // This variant introduces a loop-carried RAW dependency by making each element depend on the prior.
    // Although the initial value is zero, this creates a sequential data flow.
}
