#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin;
int nmax;
double *result_array;
int n;

void init_vars() {
    nmin = 0;
    nmax = 13421772; // Approximately 104 MB of data (13421772 * 8 bytes per double ≈ 107 MB)
    
    size_t array_size = (nmax - nmin + 1);
    result_array = (double*)aligned_alloc(32, array_size * sizeof(double));
    
    for (size_t i = 0; i < array_size; i++) {
        result_array[i] = (double)(i + 1);
    }
}