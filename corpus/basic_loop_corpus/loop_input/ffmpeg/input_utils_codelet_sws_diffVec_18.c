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
    length = 1 << 24; // ~16.7M elements, large enough for ~0.01 sec on modern CPU

    a = (SwsVector*)malloc(sizeof(SwsVector));
    a->length = 1024;
    a->coeff = (double*)calloc(a->length, sizeof(double));

    vec = (SwsVector*)malloc(sizeof(SwsVector));
    vec->length = length;
    vec->coeff = (double*)calloc(vec->length, sizeof(double));

    for (i = 0; i < a->length; i++) {
        a->coeff[i] = 1.0;
    }
}