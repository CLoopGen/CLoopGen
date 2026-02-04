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
    for (j = 0; j < number_coefficients; j += 2) {
        coeff[j] = 0.;
        if (j + 1 < number_coefficients)
            coeff[j + 1] = 0.;
    }
}
