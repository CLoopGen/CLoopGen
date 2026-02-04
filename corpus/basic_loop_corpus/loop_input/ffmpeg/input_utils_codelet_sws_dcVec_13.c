#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

SwsVector *a;
int i;
double sum;

static double *coeff_data;
static int data_length;

void init_vars() {
    data_length = 134217728 / sizeof(double);  // ~107 MB of data to target ~0.01s runtime
    coeff_data = (double *)calloc(data_length, sizeof(double));
    if (!coeff_data) {
        exit(1);
    }

    for (int j = 0; j < data_length; j++) {
        coeff_data[j] = 1.0;  // Initialize with non-zero to ensure meaningful computation
    }

    a = (SwsVector *)malloc(sizeof(SwsVector));
    if (!a) {
        free(coeff_data);
        exit(1);
    }

    a->coeff = coeff_data;
    a->length = data_length;

    i = 0;
    sum = 0.0;
}