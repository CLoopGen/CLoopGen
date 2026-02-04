#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m;
double *result_array;
int j;

void init_vars() {
    m = 16777216; // 16M elements, ~128MB for double array (8 bytes per element)
    result_array = (double *)calloc(m, sizeof(double));
    if (!result_array) {
        exit(1);
    }
    j = 0;
}