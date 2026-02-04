#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *b;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from the end to the beginning to reverse access order
    int len = b->length;
    int offset = (length - 1) / 2 - (len - 1) / 2;
    double *vec_coeff = vec->coeff;
    double *b_coeff = b->coeff;

    for (i = len - 1; i >= 0; i--) {
        vec_coeff[i + offset] -= b_coeff[i];
    }
}
