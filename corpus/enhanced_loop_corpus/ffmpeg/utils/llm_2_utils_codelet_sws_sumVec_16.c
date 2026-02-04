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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop by processing two elements at once
    int len = a->length;
    int offset = (length - 1) / 2 - (len - 1) / 2;
    int i;
    for (i = 0; i < len - 1; i += 2) {
        vec->coeff[i + offset] += a->coeff[i];
        vec->coeff[i + 1 + offset] += a->coeff[i + 1];
    }
    // Handle remaining element if length is odd
    if (i < len) {
        vec->coeff[i + offset] += a->coeff[i];
    }
}
