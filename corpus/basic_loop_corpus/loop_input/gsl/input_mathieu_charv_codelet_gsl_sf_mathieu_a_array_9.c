#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int even_order;
unsigned int ii;
double *zz;

void init_vars() {
    even_order = 4096;  // This gives even_order * even_order = 16,777,216 elements
    size_t num_elements = (size_t)even_order * even_order;
    size_t alloc_size = num_elements * sizeof(double);

    zz = (double *)calloc(num_elements, sizeof(double));
    if (!zz) {
        exit(1);
    }
}