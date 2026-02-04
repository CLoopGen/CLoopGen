#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;

void *C;

void init_vars() {
    size_t total_size = 2 * ldc * N * sizeof(double);
    C = aligned_alloc(32, total_size);
    if (!C) {
        exit(1);
    }
}