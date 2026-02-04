#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal and offset adjustment
    int start = (length - 1) / 2 - (a->length - 1) / 2;
    for (i = a->length - 1; i >= 0; i--)
        vec->coeff[start + i] += a->coeff[i];
}
