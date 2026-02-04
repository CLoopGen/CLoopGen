#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double alpha;
double *B;
int ldb;
int i;
int j;
int n1;
int n2;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldb = n2;
    alpha = 1.5;

    B = (double*)aligned_alloc(32, n1 * ldb * sizeof(double));
    if (!B) {
        exit(1);
    }

    for (int idx = 0; idx < n1 * n2; idx++) {
        B[idx] = 1.0 + (idx % 100) * 0.01;
    }
}