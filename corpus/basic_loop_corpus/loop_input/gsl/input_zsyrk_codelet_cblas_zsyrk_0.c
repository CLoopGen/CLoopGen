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
    N = 2048;
    ldc = N;
    C = aligned_alloc(32, sizeof(double) * 2 * ldc * N);
    if (!C) {
        exit(1);
    }
}