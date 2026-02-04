#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t N = 64 * 1024 * 1024 / sizeof(int); // ~256 MB of int data
int *ATp;
int *w;
size_t i;

void init_vars() {
    ATp = (int*)aligned_alloc(32, N * sizeof(int));
    w = (int*)aligned_alloc(32, N * sizeof(int));

    if (!ATp || !w) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < N; ++idx) {
        ATp[idx] = (int)(idx & 0xFF);
        w[idx] = 0;
    }
}