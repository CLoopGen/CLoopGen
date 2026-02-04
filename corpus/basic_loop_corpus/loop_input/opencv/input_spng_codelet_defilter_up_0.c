#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t bytes;
unsigned char *row;
unsigned char *prev;
size_t i;

void init_vars() {
    // Target approximately 0.01 seconds runtime on modern CPU
    // Estimate: simple arithmetic per byte, ~1-2 GB/s throughput -> aim for ~10-20 MB
    bytes = 16 * 1024 * 1024; // 16 MB

    row = (unsigned char*)aligned_alloc(32, bytes);
    prev = (unsigned char*)aligned_alloc(32, bytes);

    if (!row || !prev) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays to non-zero predictable values
    for (size_t idx = 0; idx < bytes; idx++) {
        row[idx] = (unsigned char)(idx & 0xFF);
        prev[idx] = (unsigned char)((idx >> 4) & 0xFF);
    }
}