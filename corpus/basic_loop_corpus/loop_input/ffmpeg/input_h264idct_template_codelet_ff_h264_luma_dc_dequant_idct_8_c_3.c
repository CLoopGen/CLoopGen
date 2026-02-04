#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define INPUT_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

int i;
int temp[16];
int16_t *input;

void init_vars() {
    // Allocate input array with large size to ensure meaningful execution time
    input = (int16_t*)aligned_alloc(32, INPUT_SIZE * sizeof(int16_t));
    if (!input) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Seed random number generator and initialize input data
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < INPUT_SIZE; ++idx) {
        input[idx] = (int16_t)(rand() % 65536 - 32768); // Range: [-32768, 32767]
    }

    // Ensure loop bounds are safe: loop runs for i in [0,3], each accesses 4*i+3 -> max index 15
    // So we need at least 16 elements in input, which is satisfied by our large allocation

    // Initialize temp array to zero
    memset(temp, 0, sizeof(temp));
}