#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *dp1;
double *dp2;
int len;
int i;
double sum0;

static double *arr1;
static double *arr2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512 MB of total data (2 arrays), tuned for ~0.01s
    len = data_size / sizeof(double);

    arr1 = (double *)aligned_alloc(32, len * sizeof(double));
    arr2 = (double *)aligned_alloc(32, len * sizeof(double));

    if (!arr1 || !arr2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dp1 = arr1;
    dp2 = arr2;

    for (int j = 0; j < len; j++) {
        arr1[j] = 1.0 + (j % 1000) * 0.001;
        arr2[j] = 2.0 + (j % 800) * 0.0015;
    }

    sum0 = 0.0;
    i = 0;
}