#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w2;
int x;
int32_t *b;
int32_t *temp;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure ~0.01s runtime
    w2 = (int)(data_size / sizeof(int32_t)) / 2; // Set w2 so that arrays are reasonably large

    b = (int32_t*)aligned_alloc(32, data_size);
    temp = (int32_t*)aligned_alloc(32, data_size);

    if (!b || !temp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize b with non-zero values for meaningful computation
    for (size_t i = 0; i < data_size / sizeof(int32_t); ++i) {
        b[i] = (int32_t)(rand() & 0xFFFF);
    }

    // Ensure temp is initialized to avoid undefined behavior in first access
    memset(temp, 0, data_size);
}