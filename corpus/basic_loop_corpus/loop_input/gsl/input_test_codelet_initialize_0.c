#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *data;
size_t N;
size_t i;

void init_vars() {
    N = 16777216; // Approximately 128 MB of data (16M * 8 bytes per double)
    data = (double*)aligned_alloc(32, N * sizeof(double));
    if (!data) {
        exit(1);
    }
    i = 0;
}