#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni = 1048576; // 1MB of integers (1048576 elements)

int *right;
int *p;
int i;

void init_vars() {
    right = (int*)aligned_alloc(32, ni * sizeof(int));
    p = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!right || !p) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < ni; ++i) {
        p[i] = rand();
    }
}