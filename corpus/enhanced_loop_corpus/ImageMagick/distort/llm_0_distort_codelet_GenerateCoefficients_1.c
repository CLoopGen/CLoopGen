#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *coeff;
extern size_t i;
extern size_t number_coefficients;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < number_coefficients; j++) {
        for (size_t i = j; i <= j; i++)
            coeff[i] = 0.;
    }
}
