#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int n = 10000000; // 10 million elements for ~0.01 sec runtime
int nc = 100;
double *data;
size_t *p;

void init_vars() {
    data = (double *)calloc(n, sizeof(double));
    p = (size_t *)malloc(n * sizeof(size_t));

    for (int idx = 0; idx < n; idx++) {
        p[idx] = idx % n; // ensure valid index within [0, n-1]
    }
}