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
    if (number_values > 0) {
        for (size_t i = 0; i < number_values; i++) {
            vectors[i] = &(coeff[i * 4]);
            // Introduce artificial nested structure with a fixed single iteration
            for (size_t j = 0; j < 1; j++) {
                // No-op inner loop to increase nesting depth without changing logic
            }
        }
    }
}
