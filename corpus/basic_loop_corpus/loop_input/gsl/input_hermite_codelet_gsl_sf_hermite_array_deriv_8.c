#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmax;
double *result_array;
int j;

void init_vars() {
    nmax = 13421772; // Approximately 104 MB of data (nmax+1 doubles, each 8 bytes)
    result_array = (double*)calloc((nmax + 1), sizeof(double));
    if (!result_array) {
        exit(1);
    }
}