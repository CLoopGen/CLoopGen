#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 10000000;
double *result_array = NULL;
int n;

void init_vars() {
    result_array = (double*)calloc((nmax - nmin + 1), sizeof(double));
    if (!result_array) {
        exit(1);
    }
}