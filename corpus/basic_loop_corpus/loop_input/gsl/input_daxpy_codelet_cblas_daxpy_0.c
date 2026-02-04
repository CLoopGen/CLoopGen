#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double alpha;
double *X;
double *Y;
int i;
int m;

void init_vars() {
    m = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    alpha = 1.5;

    X = (double *)malloc(m * sizeof(double));
    Y = (double *)malloc(m * sizeof(double));

    for (int j = 0; j < m; j++) {
        X[j] = (double)(j % 123) + 1.0;
        Y[j] = (double)(j % 456) + 2.0;
    }
}