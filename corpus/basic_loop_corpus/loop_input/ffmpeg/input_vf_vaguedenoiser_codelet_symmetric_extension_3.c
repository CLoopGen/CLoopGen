#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *output;
int first;
int i;
int nextend;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128 MB of float data
    output = (float*)malloc(data_size);
    if (!output) {
        exit(1);
    }

    nextend = 32 * 1024 * 1024; // Process 32M elements to take ~0.01s
    first = 32 * 1024 * 1024 + 10 + 1; // Ensure --first starts at valid index

    // Initialize source region: [11, 11 + nextend - 1]
    for (int idx = 0; idx < nextend; idx++) {
        output[10 + 1 + idx] = (float)(idx * 2);
    }

    // Pre-fill destination region to avoid undefined behavior if inspected
    for (int idx = 0; idx < nextend; idx++) {
        output[--first] = 0.0f;
    }

    // Reset first and prepare for loop: first should be one past the last target index
    first = 32 * 1024 * 1024 + 10 + 1;
}