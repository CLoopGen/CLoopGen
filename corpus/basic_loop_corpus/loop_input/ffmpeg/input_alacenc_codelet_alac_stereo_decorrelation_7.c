#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *left;
int32_t *right;
int i;
int n;

void init_vars() {
    n = 67108864; // Approximately 256MB of data (67M elements * 4 bytes * 2 arrays)

    left = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    right = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    for (int j = 0; j < n; j++) {
        left[j] = (int32_t)(j % 1000);
        right[j] = (int32_t)((j + 500) % 1000);
    }
}