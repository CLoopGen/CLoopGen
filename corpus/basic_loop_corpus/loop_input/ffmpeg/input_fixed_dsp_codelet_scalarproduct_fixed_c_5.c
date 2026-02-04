#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int *v1;
int *v2;
int len;
int64_t p;
int i;

void init_vars() {
    // Estimate data size for ~0.01 seconds runtime
    // Assume modern CPU can do ~1e9 operations/sec -> target ~1e7 iterations
    len = 10000000; // 10 million elements

    v1 = (int*)aligned_alloc(32, len * sizeof(int));
    v2 = (int*)aligned_alloc(32, len * sizeof(int));

    if (!v1 || !v2) {
        exit(1);
    }

    // Initialize arrays with predictable values to allow compiler optimizations
    // but avoid all-zero patterns
    for (int j = 0; j < len; j++) {
        v1[j] = (j % 100) - 50;
        v2[j] = (j % 75) - 37;
    }

    p = 0;
    i = 0;
}