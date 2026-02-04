#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int x;
int w2 = 131072; // Size chosen so that the loop runs ~0.01s; 131072 iterations reasonable for modern CPU
int32_t *b;
int32_t *tmp;

void init_vars() {
    const size_t data_size = (size_t)w2;
    const size_t b_size = 2 * data_size + data_size; // b accessed up to index [2*x+1] and [x + w2], so max index ~ 2*w2 - 1 + w2? but x < w2 -> x+w2 < 2*w2
    // Max index in b: 
    //   - b[2*x] -> 2*(w2-1)
    //   - b[2*x+1] -> 2*(w2-1)+1 = 2*w2 - 1
    //   - b[x + w2] -> (w2-1) + w2 = 2*w2 - 1
    // So we need b of size at least 2*w2
    const size_t total_b_size = 2 * data_size;

    b = (int32_t*)aligned_alloc(32, total_b_size * sizeof(int32_t));
    tmp = (int32_t*)aligned_alloc(32, (data_size + 2) * sizeof(int32_t)); // tmp accessed at x, x+1, x+2, x-1 -> needs extra guard elements

    if (!b || !tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize all memory to prevent undefined behavior
    memset(b, 0, total_b_size * sizeof(int32_t));
    memset(tmp, 0, (data_size + 2) * sizeof(int32_t));

    // Optional: fill with predictable pattern to simulate real usage
    for (size_t i = 0; i < data_size + 2; i++) {
        tmp[i] = (int32_t)(i * 7919) % 1000; // Prime multiplier
    }
    for (size_t i = 0; i < total_b_size; i++) {
        b[i] = (int32_t)(i * 97) % 2000;
    }
}