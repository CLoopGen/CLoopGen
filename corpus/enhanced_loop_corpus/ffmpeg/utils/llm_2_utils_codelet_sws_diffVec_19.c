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
    // Process elements in two interleaved sequences to modify access pattern
    int len = b->length;
    int offset = (length - 1) / 2 - (len - 1) / 2;
    double *vec_coeff = vec->coeff;
    double *b_coeff = b->coeff;

    for (i = 0; i < len; i += 2) {
        if (i < len) {
            vec_coeff[i + offset] -= b_coeff[i];
        }
        if (i + 1 < len) {
            vec_coeff[i + 1 + offset] -= b_coeff[i + 1];
        }
    }
}
