#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *left;
int32_t *right;
int i;
int n;
int32_t tmp;

void init_vars() {
    n = 32 * 1024 * 1024 / sizeof(int32_t); // ~128MB total data (64MB per array)

    left = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    right = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    if (!left || !right) {
        exit(1);
    }

    for (int j = 0; j < n; j++) {
        left[j] = (int32_t)(j * 2);
        right[j] = (int32_t)(j * 3);
    }

    i = 0;
    tmp = 0;
}