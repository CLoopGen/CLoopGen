#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

static double *vec_coeff;
static double *b_coeff;
SwsVector *b;
SwsVector *vec;
int length;
int i;

void init_vars() {
    length = 1 << 24; // ~16.7 million elements, aiming for ~0.01 sec on modern CPU
    int b_length = 1 << 20; // 1M coefficients for b

    vec_coeff = (double *)calloc(length, sizeof(double));
    b_coeff = (double *)malloc(b_length * sizeof(double));

    b = (SwsVector *)malloc(sizeof(SwsVector));
    vec = (SwsVector *)malloc(sizeof(SwsVector));

    b->coeff = b_coeff;
    b->length = b_length;
    vec->coeff = vec_coeff;
    vec->length = length;

    int offset = (length - 1) / 2 - (b_length - 1) / 2;
    // Ensure no out-of-bounds access: i + offset < length and i + offset >= 0
    // max i is b_length-1 -> (b_length-1) + offset < length
    // offset = (length - 1)/2 - (b_length - 1)/2
    // so (b_length-1) + offset = (b_length-1) + (length-1)/2 - (b_length-1)/2
    // <= (length-1)/2 + (b_length-1)/2 < length for reasonable sizes

    for (int j = 0; j < b_length; j++) {
        b_coeff[j] = 1.0; // arbitrary initialization
    }
    for (int j = 0; j < length; j++) {
        vec_coeff[j] = 0.0;
    }
}