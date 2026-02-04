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
    n1 = 512;
    n2 = 512;
    ldc = n2;
    size_t total_size = 2 * ldc * n1 * sizeof(float);
    C = aligned_alloc(32, total_size);
}