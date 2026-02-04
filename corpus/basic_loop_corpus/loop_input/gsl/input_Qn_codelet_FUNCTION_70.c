#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 32 * 1024 * 1024 / sizeof(int); // ~128 MB of data for int arrays

    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!left || !q) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        q[j] = j;
        left[j] = 0;
    }
}