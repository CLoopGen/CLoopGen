#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *a;
int length;
int i;
SwsVector *vec;

void init_vars() {
    length = 1 << 20; // Approximately 8MB of data (1M doubles), should run in ~0.01s

    a = (SwsVector *)malloc(sizeof(SwsVector));
    a->length = 1 << 18; // 256K coefficients
    a->coeff = (double *)calloc(a->length, sizeof(double));

    vec = (SwsVector *)malloc(sizeof(SwsVector));
    vec->length = length;
    vec->coeff = (double *)calloc(vec->length, sizeof(double));

    // Ensure no out-of-bounds access:
    // i from 0 to a->length-1
    // index in vec: i + (length-1)/2 - (a->length-1)/2
    // must be within [0, vec->length-1]
    //
    // min index: 0 + (length-1)/2 - (a->length-1)/2
    // max index: (a->length-1) + (length-1)/2 - (a->length-1)/2 = (length-1)/2 + (a->length-1)/2
    //
    // We require:
    //   (length-1)/2 - (a->length-1)/2 >= 0  --> length >= a->length
    //   (length-1)/2 + (a->length-1)/2 < length --> always true when a->length <= length
    //
    // With length = 1M, a->length = 256K, the offset is positive and within bounds.

    for (i = 0; i < a->length; i++) {
        a->coeff[i] = 1.0; // arbitrary initialization
    }
    for (i = 0; i < vec->length; i++) {
        vec->coeff[i] = 0.0;
    }
}