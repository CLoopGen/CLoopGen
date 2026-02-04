#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *C;
int ldc;
int i;

void init_vars() {
    N = 10000;
    ldc = N;
    C = aligned_alloc(32, sizeof(double) * (ldc * N + N) * 2);
    if (!C) exit(1);
}