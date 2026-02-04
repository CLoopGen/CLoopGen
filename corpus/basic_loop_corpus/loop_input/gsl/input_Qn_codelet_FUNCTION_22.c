#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *q;
int i;

void init_vars() {
    ni = 1 << 24; // 16M integers, ~64MB total data (32MB each for left and q)
    left = (int *)aligned_alloc(32, ni * sizeof(int));
    q = (int *)aligned_alloc(32, ni * sizeof(int));

    if (!left || !q) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        q[j] = j * 3 + 1;
        left[j] = 0;
    }
}