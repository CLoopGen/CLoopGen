#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *C;
int ldc;
int i;
int j;
int n1;
int n2;

void init_vars() {
    n1 = 4096;
    n2 = 4096;
    ldc = n2;
    size_t total_size = (size_t)ldc * n1 * sizeof(double) * 2;
    C = aligned_alloc(32, total_size);
    if (!C) {
        exit(1);
    }
}