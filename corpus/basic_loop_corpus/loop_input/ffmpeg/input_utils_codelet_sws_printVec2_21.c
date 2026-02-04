#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *a;
int i;
double max;

void init_vars() {
    const int data_size = 32000000; // ~256 MB of doubles (each double is 8 bytes)
    a = (SwsVector *)malloc(sizeof(SwsVector));
    a->coeff = (double *)malloc(data_size * sizeof(double));
    a->length = data_size;

    for (int j = 0; j < data_size; j++) {
        a->coeff[j] = (double)(rand() % 100000) / 100.0;
    }

    max = -__builtin_huge_val();
}

__attribute__((constructor)) void setup() {
    init_vars();
}