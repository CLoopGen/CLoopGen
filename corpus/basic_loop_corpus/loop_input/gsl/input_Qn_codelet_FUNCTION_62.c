#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 32 * 1024 * 1024 / sizeof(int); // ~128 MB of data
    left = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    for (int j = 0; j < ni; ++j) {
        q[j] = j * 2 + 1;
        left[j] = 0;
    }
}