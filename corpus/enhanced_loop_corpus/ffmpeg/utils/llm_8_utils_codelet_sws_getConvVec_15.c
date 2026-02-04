#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern SwsVector *b;
extern int i;
extern int j;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling inner loop and increasing arithmetic operations
    for (i = 0; i < a->length; i++) {
        double a_coeff_i = a->coeff[i];
        for (j = 0; j < b->length - 3; j += 4) {
            vec->coeff[i + j]     += a_coeff_i * b->coeff[j];
            vec->coeff[i + j + 1] += a_coeff_i * b->coeff[j + 1];
            vec->coeff[i + j + 2] += a_coeff_i * b->coeff[j + 2];
            vec->coeff[i + j + 3] += a_coeff_i * b->coeff[j + 3];
        }
        // Handle remaining elements
        for (; j < b->length; j++) {
            vec->coeff[i + j] += a->coeff[i] * b->coeff[j];
        }
    }
}
