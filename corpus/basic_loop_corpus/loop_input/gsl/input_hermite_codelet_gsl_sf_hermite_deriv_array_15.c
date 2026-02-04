#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mmax;
int n;
double *result_array;
int j;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // ~128MB of double data
    size_t num_elements = data_size / sizeof(double);
    
    result_array = (double*)calloc(num_elements, sizeof(double));
    
    if (!result_array) {
        exit(1);
    }
    
    mmax = (int)(num_elements - 1);
    n = (mmax > 10) ? 10 : 0;
}