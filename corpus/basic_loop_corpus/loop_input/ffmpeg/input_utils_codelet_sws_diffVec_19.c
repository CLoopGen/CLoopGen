#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *b;
int length;
int i;
SwsVector *vec;

void init_vars() {
    length = 1 << 20; // Approximately 8MB of data (1M doubles), should run in ~0.01s

    b = (SwsVector*)malloc(sizeof(SwsVector));
    b->length = 1000;
    b->coeff = (double*)calloc(b->length, sizeof(double));

    vec = (SwsVector*)malloc(sizeof(SwsVector));
    vec->length = length + b->length - 1;
    vec->coeff = (double*)calloc(vec->length, sizeof(double));

    // Ensure no out-of-bounds access:
    // i from 0 to b->length-1
    // index in vec: i + (length-1)/2 - (b->length-1)/2
    // max index: (b->length-1) + (length-1)/2 - (b->length-1)/2 = (length-1)/2 + (b->length-1)/2
    // needs to be < vec->length -> satisfied since (length-1)/2 + (b->length-1)/2 < length + b->length - 1 for length >= 1
}