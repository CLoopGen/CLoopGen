#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x = 131072;
int y = 8;

static double *data_storage;
static double **pointers_storage;

double *data;
double **pointers;
int i;

void init_vars() {
    const size_t data_size = (size_t)x * y;
    data_storage = aligned_alloc(32, data_size * sizeof(double));
    pointers_storage = aligned_alloc(32, x * sizeof(double*));

    if (!data_storage || !pointers_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        data_storage[idx] = (double)(idx * 1.5);
    }

    data = data_storage;
    pointers = pointers_storage;
}