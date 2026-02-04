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
    for (i = 0; i < number_coefficients; i++) {
        double temp = 1.0;
        for (j = 0; j < 5; j++) {
            temp = temp * 1.1 + coeff[i];
        }
        coeff[i] = temp - 5.0;
    }
}
