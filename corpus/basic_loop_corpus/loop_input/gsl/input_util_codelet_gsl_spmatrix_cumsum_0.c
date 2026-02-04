#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t n;
int *c;
int sum;
size_t k;

void init_vars() {
    n = 32 * 1024 * 1024 / sizeof(int);  // ~128MB of data to target ~0.01s runtime
    c = (int*)aligned_alloc(64, n * sizeof(int));
    if (!c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < n; ++i) {
        c[i] = (int)(i % 1000);
    }
    sum = 0;
    k = 0;
}