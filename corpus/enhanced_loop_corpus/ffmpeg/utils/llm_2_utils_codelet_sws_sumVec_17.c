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
    // Variant 1: Strided memory access with stride of 2 (unrolling-like pattern)
    int len = b->length;
    int offset = (length - 1) / 2 - (len - 1) / 2;
    int i;

    // Process even indices first with stride 2
    for (i = 0; i < len; i += 2)
        vec->coeff[i + offset] += b->coeff[i];

    // Process odd indices with stride 2
    for (i = 1; i < len; i += 2)
        vec->coeff[i + offset] += b->coeff[i];
}
