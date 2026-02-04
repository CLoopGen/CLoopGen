#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t N = 65536;
size_t stride = 4;
size_t i;
double *data;

void init_vars() {
    data = aligned_alloc(32, N * stride * sizeof(double));
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}