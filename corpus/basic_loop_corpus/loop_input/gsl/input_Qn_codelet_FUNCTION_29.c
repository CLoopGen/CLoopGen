#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

void init_vars() {
    ni = 1 << 20; // 1 million elements, ~4MB per array (sufficient for ~0.01 sec on modern CPU)

    right = (int*)aligned_alloc(32, ni * sizeof(int));
    p = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!right || !p) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p[j] = rand();
    }
}