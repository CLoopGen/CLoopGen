#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 4096;
int ldc = 4096;
int i, j;

void *C;

void init_vars() {
    C = aligned_alloc(32, sizeof(double) * 2 * ldc * N);
    if (C == NULL) {
        exit(1);
    }
}