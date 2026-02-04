#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *arguments;
extern size_t number_values;
extern double *coeff;
extern size_t i;
extern size_t cp_values;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < number_values; j += 2) {
        if (j + 1 < number_values) {
            coeff[j * 3 + 2] = arguments[cp_values + j];
            coeff[(j + 1) * 3 + 2] = arguments[cp_values + j + 1];
        } else {
            coeff[j * 3 + 2] = arguments[cp_values + j];
        }
    }
}
