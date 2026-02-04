#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 13421772; // ~107.4 MB of data (13421772 * 8 bytes per double)
double ex = 1.5;
int i;

double *result_array;

void init_vars() {
    ptrdiff_t size = nmax - nmin;
    result_array = (double*)calloc(size + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
    for (ptrdiff_t idx = 0; idx <= size; idx++) {
        result_array[idx] = 2.0;
    }
}