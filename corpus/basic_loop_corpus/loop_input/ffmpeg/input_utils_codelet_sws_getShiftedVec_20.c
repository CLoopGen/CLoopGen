#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *a;
int shift;
int length;
int i;
SwsVector *vec;

void init_vars() {
    length = 1 << 20; // Approximately 8MB of data (1M doubles), should run in ~0.01s
    shift = length / 4;
    a = (SwsVector *)malloc(sizeof(SwsVector));
    a->length = length / 2;
    a->coeff = (double *)malloc(a->length * sizeof(double));

    vec = (SwsVector *)malloc(sizeof(SwsVector));
    vec->length = length;
    vec->coeff = (double *)malloc(vec->length * sizeof(double));

    for (i = 0; i < a->length; i++) {
        a->coeff[i] = (double)(i + 1);
        vec->coeff[i] = 0.0;
    }

    for (; i < vec->length; i++) {
        vec->coeff[i] = 0.0;
    }
}