#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m;
double *result_array;
int j;

void init_vars() {
    m = 134217728; // 134M elements ≈ 1GB for double, adjusted to target ~0.01 sec runtime
    result_array = (double *)calloc(m, sizeof(double));
    j = 0;
}