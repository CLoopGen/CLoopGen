#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 32 * 1024 * 1024 / sizeof(int);  // ~128 MB of data for int arrays

    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!left || !q) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < ni; ++idx) {
        q[idx] = rand();
    }

    for (int idx = 0; idx < ni; ++idx) {
        left[idx] = 0;
    }
}