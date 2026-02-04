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
    N = 512;
    size_t total_size = ldc * N * 2 * sizeof(float);
    if (total_size < 1024*1024) {
        total_size = 1024*1024;
        N = (total_size / sizeof(float)) / (2 * ldc);
        if (N == 0) N = 1;
    }
    C = aligned_alloc(32, total_size);
}