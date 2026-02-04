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
    // Variant 2: Strided access with reverse traversal
    for (i = number_values; i-- > 0; ) {
        vectors[i] = &(coeff[(number_values - 1 - i) * 3]); // Reverse strided indexing
    }
}
