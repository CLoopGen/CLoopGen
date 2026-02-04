#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

long *x;
int n = 10000000;  // ~80 MB for long array, sufficient for ~0.01 sec runtime
int i;

void init_vars() {
    x = (long*)aligned_alloc(64, n * sizeof(long));
    if (!x) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize base value to avoid undefined behavior in recurrence
    x[0] = 123456789;

    // Initialize remaining elements to zero (they will be overwritten by loop)
    for (int j = 1; j < n; j++) {
        x[j] = 0;
    }
}