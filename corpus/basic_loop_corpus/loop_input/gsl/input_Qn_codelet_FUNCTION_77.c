#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

void init_vars() {
    ni = 32 * 1024 * 1024 / sizeof(int);  // ~128MB of data to target ~0.01 sec on modern CPU

    p = (int*)aligned_alloc(64, ni * sizeof(int));
    right = (int*)aligned_alloc(64, ni * sizeof(int));

    if (!p || !right) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < ni; ++idx) {
        p[idx] = idx * 2 + 1;
        right[idx] = 0;
    }
}