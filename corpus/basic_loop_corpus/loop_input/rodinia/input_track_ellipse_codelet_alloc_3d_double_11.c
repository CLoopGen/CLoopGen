#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x = 4096;
int y = 64;
int z = 16;
double *data;
double **pointers_to_data;
int i;

void init_vars() {
    size_t total_elements = (size_t)x * y;
    size_t data_size = total_elements * z;

    data = (double *)aligned_alloc(32, data_size * sizeof(double));
    pointers_to_data = (double **)aligned_alloc(32, total_elements * sizeof(double *));

    if (!data || !pointers_to_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data[idx] = (double)(idx & 511);
    }

    for (size_t idx = 0; idx < total_elements; ++idx) {
        pointers_to_data[idx] = NULL;
    }
}