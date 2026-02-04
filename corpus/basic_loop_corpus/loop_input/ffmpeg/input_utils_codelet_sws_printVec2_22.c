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
double min;

void init_vars() {
    const int data_size = 25000000; // ~200 MB for double array (25e6 * 8 bytes)
    a = (SwsVector *)malloc(sizeof(SwsVector));
    a->coeff = (double *)malloc(data_size * sizeof(double));
    a->length = data_size;

    for (int j = 0; j < data_size; j++) {
        a->coeff[j] = (double)(rand() % 10000) / 10.0; // Random values between 0 and 999.9
    }

    min = a->coeff[0];
    i = 0;
}