#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *C;
int ldc;
int i;
int j;

void init_vars() {
    N = 1024;
    ldc = N;
    C = aligned_alloc(32, sizeof(double) * 2 * ldc * N);
    if (!C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}

__attribute__((destructor))
static void cleanup() {
    if (C) free(C);
}