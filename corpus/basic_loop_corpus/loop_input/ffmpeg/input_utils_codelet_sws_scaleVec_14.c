#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *a;
double scalar;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of double data to ensure loop takes ~0.01s
    const int length = data_size / sizeof(double);

    a = (SwsVector *)malloc(sizeof(SwsVector));
    if (!a) exit(1);

    a->coeff = (double *)malloc(length * sizeof(double));
    if (!a->coeff) exit(1);

    a->length = length;

    for (int j = 0; j < length; j++) {
        a->coeff[j] = (double)(j % 1000) + 1.0;
    }

    scalar = 1.5;
}