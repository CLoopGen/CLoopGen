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
    n = 32000000; // Approximately 128MB of data (32M elements * 4 bytes * 2 arrays)

    left = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    right = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    if (!left || !right) {
        exit(1);
    }

    for (int idx = 0; idx < n; idx++) {
        left[idx] = (int32_t)(idx % 256);
        right[idx] = (int32_t)((idx + 128) % 256) - 128;
    }
}