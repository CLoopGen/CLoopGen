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
    n = 16777216; // 16M elements, ~128MB total for two int32_t arrays

    left = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    right = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    for (int j = 0; j < n; j++) {
        left[j] = (int32_t)(j % 1000);
        right[j] = (int32_t)((j + 500) % 1000);
    }
}