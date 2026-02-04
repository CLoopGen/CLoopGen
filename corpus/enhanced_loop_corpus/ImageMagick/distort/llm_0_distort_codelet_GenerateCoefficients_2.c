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
    for (size_t outer = 0; outer < number_values; outer++) {
        for (size_t inner = 0; inner < 1; inner++) {
            coeff[outer * 3 + 2] = arguments[cp_values + outer];
        }
    }
}
