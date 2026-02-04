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
    for (i = 0; i < number_values * 2; i++) {
        size_t idx = i / 2;
        coeff[idx * 3 + 2] = arguments[cp_values + idx] + arguments[cp_values + idx] * 0.5;
    }
}
