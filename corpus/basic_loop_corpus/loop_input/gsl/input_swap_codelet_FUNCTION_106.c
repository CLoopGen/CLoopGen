#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M;
int *ATp;
int *w;
size_t j;

void init_vars() {
    M = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of integers to target ~0.01s runtime

    ATp = (int*)aligned_alloc(32, M * sizeof(int));
    w = (int*)aligned_alloc(32, M * sizeof(int));

    if (!ATp || !w) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < M; ++i) {
        ATp[i] = (int)(i & 0xFF);
        w[i] = 0;
    }
}