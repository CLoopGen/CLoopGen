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

    size_t total_elements = n1 * ldc;
    size_t total_bytes = total_elements * sizeof(double) * 2; // complex-like: 2 doubles per element

    C = aligned_alloc(32, total_bytes);
    if (!C) {
        exit(1);
    }
}