#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *left;
int32_t *right;
int i;
int n;

void init_vars() {
    n = 65536; // Size chosen to process around 1MB of data (65536 * 4 bytes * 2 arrays ≈ 0.5MB)
    left = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));
    right = (int32_t*)aligned_alloc(32, n * sizeof(int32_t));

    for (int j = 0; j < n; j++) {
        left[j] = (int32_t)(j * 2);
        right[j] = (int32_t)(j + 1);
    }
}