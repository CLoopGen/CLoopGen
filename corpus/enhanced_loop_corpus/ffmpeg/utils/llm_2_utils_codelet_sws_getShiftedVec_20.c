#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int shift;
extern int length;
extern int i;
extern SwsVector *vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (unrolling-like pattern)
    // This variant processes two elements per iteration in a strided manner, assuming even length for simplicity.
    int len = a->length;
    int offset = (length - 1) / 2 - (a->length - 1) / 2 - shift;
    int i;
    for (i = 0; i < len; i += 2) {
        vec->coeff[i + offset] = a->coeff[i];
        if (i + 1 < len) {
            vec->coeff[i + 1 + offset] = a->coeff[i + 1];
        }
    }
}
