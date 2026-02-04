#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *result;
int n2;
int i;

void init_vars() {
    n2 = 1 << 20;  // 1 million elements, adjust for ~0.01 sec runtime
    size_t total_size = 2 * n2;  // Ensure access up to result[n2 + i] with i < n2
    result = (float*)calloc(total_size, sizeof(float));
    if (!result) {
        exit(1);
    }
    // Initialize source region to avoid undefined behavior
    for (int j = 0; j < n2; j++) {
        result[j] = (float)(j + 1);
    }
}