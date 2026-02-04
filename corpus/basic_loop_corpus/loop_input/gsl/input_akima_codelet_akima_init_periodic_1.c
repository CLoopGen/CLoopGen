#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double x_array[ARRAY_SIZE];
double y_array[ARRAY_SIZE];
size_t size = ARRAY_SIZE;
double *m;
size_t i;

void init_vars() {
    m = malloc((size - 1) * sizeof(double));
    if (!m) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < size; idx++) {
        x_array[idx] = (double)(idx + 1);
        y_array[idx] = (double)((idx % 123) * (idx % 456));
    }
}