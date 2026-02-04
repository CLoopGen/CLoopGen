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
    for (i = 1; i < number_values; i++)
        coeff[i * 3 + 2] = arguments[cp_values + i] + coeff[(i - 1) * 3 + 2];
    if (number_values > 0)
        coeff[2] = arguments[cp_values];
}
