#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m;
double *result_array;
int j;

void init_vars() {
    m = 134217728; // 134 million elements ~ 1GB for double, aiming for >0.01s runtime
    result_array = (double *)calloc(m, sizeof(double));
    j = 0;
}