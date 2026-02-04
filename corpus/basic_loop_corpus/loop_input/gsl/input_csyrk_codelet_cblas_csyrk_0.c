#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 1024;
int ldc = 1024;
int i, j;

void *C;

void init_vars() {
    C = aligned_alloc(32, sizeof(float) * 2 * ldc * N);
    if (C == NULL) {
        exit(1);
    }
}