#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_values;
extern double *coeff;
extern size_t i;
extern double **vectors;
extern size_t nterms;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double **temp_vectors = vectors;
    double *temp_coeff = coeff;
    size_t local_nterms = nterms;
    size_t local_num = number_values;
    for (i = 0; i < local_num; i++) {
        temp_vectors[i] = &(temp_coeff[2 + i * local_nterms]);
    }
    vectors = temp_vectors;
}
