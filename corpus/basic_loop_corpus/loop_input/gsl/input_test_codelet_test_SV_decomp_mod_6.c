#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double lower = 3.14159;
double *a;

void init_vars() {
    size_t num_elements = 268435456 / sizeof(double); // ~256MB of data
    if (num_elements < 16) num_elements = 16;
    a = (double*)aligned_alloc(32, num_elements * sizeof(double));
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}