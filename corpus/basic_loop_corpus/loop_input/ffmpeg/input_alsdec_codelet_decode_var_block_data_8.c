#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int opt_order = 32;
int sb;
int64_t y;
int32_t *lpc_cof;
int32_t *raw_samples;
int32_t *raw_samples_end;

static int32_t *lpc_cof_buffer;
static int32_t *raw_samples_buffer;

void init_vars() {
    const size_t raw_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    const int max_order = opt_order;

    // Allocate buffers with padding for negative indexing
    lpc_cof_buffer = (int32_t*)aligned_alloc(32, (max_order + 64) * sizeof(int32_t));
    raw_samples_buffer = (int32_t*)aligned_alloc(32, raw_size + (max_order + 64) * sizeof(int32_t));

    if (!lpc_cof_buffer || !raw_samples_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize lpc_cof to point past offset to allow negative indexing from -opt_order
    lpc_cof = lpc_cof_buffer + max_order;

    // Initialize raw_samples to point past padding
    raw_samples = raw_samples_buffer + max_order;
    raw_samples_end = raw_samples + (raw_size / sizeof(int32_t)) - max_order;

    // Initialize arrays with non-zero values to avoid degenerate optimization cases
    for (int i = 0; i < max_order; i++) {
        lpc_cof_buffer[i] = (rand() % 2000) - 1000; // Random coefficients in reasonable range
    }

    for (size_t i = 0; i < (raw_size / sizeof(int32_t)); i++) {
        raw_samples_buffer[max_order + i] = (rand() % 65536) - 32768;
    }
}