#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int w2;
int x;
int16_t *b;
int16_t *tmp;

void init_vars() {
    // Set problem size to achieve ~0.01s runtime
    // Based on typical performance, w2 around 100k-200k elements gives desired timing
    w2 = 131072;  // 128K elements -> total data ~512KB

    // Allocate arrays with proper bounds: loop accesses b[x + w2 - 2] up to x = w2-2
    // Maximum index: (w2-2) + w2 - 2 = 2*w2 - 4, so we need at least 2*w2 - 3 elements in b
    size_t b_size = 2 * w2 + 10;  // Add padding to be safe
    size_t tmp_size = w2;       // tmp accessed from 2 to w2-2

    b = (int16_t*)aligned_alloc(32, b_size * sizeof(int16_t));
    tmp = (int16_t*)aligned_alloc(32, tmp_size * sizeof(int16_t));

    // Initialize b with random-like data to prevent optimization away
    for (size_t i = 0; i < b_size; i++) {
        b[i] = (int16_t)(i * 7919) ^ (int16_t)(i >> 3);  // Prime-based pattern
    }

    // Initialize tmp to zero
    memset(tmp, 0, tmp_size * sizeof(int16_t));
}