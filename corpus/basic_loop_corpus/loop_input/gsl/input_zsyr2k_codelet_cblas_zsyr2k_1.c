#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;

void *C;

void init_vars() {
    size_t total_elements = ldc * N;
    C = aligned_alloc(32, total_elements * 2 * sizeof(double));
    if (C == NULL) {
        exit(EXIT_FAILURE);
    }
}