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

    size_t total_elements = (size_t)n1 * n2;
    B = (double*)aligned_alloc(32, total_elements * sizeof(double));
    
    for (size_t idx = 0; idx < total_elements; idx++) {
        B[idx] = (double)(idx % 127) + 1.0;
    }
}