#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *C;
int ldc;
int i;

void init_vars() {
    ldc = 1024;
    N = 1024;
    C = aligned_alloc(32, ldc * N * sizeof(float) * 2);
    if (!C) {
        exit(1);
    }
}