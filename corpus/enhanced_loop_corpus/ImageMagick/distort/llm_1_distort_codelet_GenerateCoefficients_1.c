#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *coeff;
extern size_t i;
extern size_t number_coefficients;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < 1; outer++)
        for (i = 0; i < number_coefficients; i++)
            coeff[i] = 0.;
}
