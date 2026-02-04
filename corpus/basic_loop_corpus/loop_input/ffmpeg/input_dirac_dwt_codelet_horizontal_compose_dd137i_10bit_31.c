#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w2;
int x;
int32_t *b;
int32_t *tmp;

void init_vars() {
    // Set problem size to achieve ~0.01 seconds runtime
    // Based on typical performance, aim for about 64-128MB of data
    w2 = 16384;  // This makes the array length w2, and loop runs from 2 to w2-2

    // Allocate arrays with padding to prevent out-of-bounds access
    // Maximum index used: x + w2 + 1, where x < w2 - 1 => max index = (w2 - 2) + w2 + 1 = 2*w2 -1
    // So we need at least 2*w2 elements in b
    b = (int32_t*)aligned_alloc(32, sizeof(int32_t) * (2 * w2 + 2));
    tmp = (int32_t*)aligned_alloc(32, sizeof(int32_t) * (w2 + 2));

    // Initialize b with random data to simulate real input
    for (int i = 0; i < 2 * w2 + 2; i++) {
        b[i] = rand() & 0xFFFF;  // Small positive values to avoid overflow issues
    }

    // Initialize tmp to zero
    memset(tmp, 0, sizeof(int32_t) * (w2 + 2));
}