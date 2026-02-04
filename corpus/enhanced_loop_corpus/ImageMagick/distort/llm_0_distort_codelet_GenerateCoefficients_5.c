#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_values;
extern double *coeff;
extern size_t i;
extern double **vectors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t outer = 0; outer < number_values; outer += 2) {
        for (size_t inner = 0; inner < 2 && (outer + inner) < number_values; inner++) {
            size_t i = outer + inner;
            vectors[i] = &(coeff[i * 4]);
        }
    }
}
