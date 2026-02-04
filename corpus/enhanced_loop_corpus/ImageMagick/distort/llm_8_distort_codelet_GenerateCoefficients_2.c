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
    for (i = 0; i < number_values; i += 2) {
        if (i + 1 < number_values) {
            coeff[i * 3 + 2] = arguments[cp_values + i];
            coeff[(i + 1) * 3 + 2] = arguments[cp_values + i + 1];
        } else {
            coeff[i * 3 + 2] = arguments[cp_values + i];
        }
    }
}
