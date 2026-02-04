#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin = 0;
int nmax = 13421772; // Size chosen to allocate ~108 MB for result_array, targeting ~0.01 sec runtime
double *result_array = NULL;
int n = 0;

void init_vars() {
    size_t num_elements = (size_t)(nmax - nmin + 1);
    result_array = (double*)calloc(num_elements, sizeof(double));
    if (!result_array) {
        fprintf(stderr, "Failed to allocate memory for result_array\n");
        exit(EXIT_FAILURE);
    }
}