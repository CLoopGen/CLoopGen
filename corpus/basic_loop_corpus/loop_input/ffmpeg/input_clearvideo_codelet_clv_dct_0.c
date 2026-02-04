#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int16_t *ptr;

static int16_t *data_buffer;
static size_t total_elements;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01 sec runtime
    // Each iteration processes 8 elements, and we assume modern CPU does ~1e9 ops/sec
    const size_t target_bytes = 64 * 1024 * 1024;
    const size_t element_size = sizeof(int16_t);
    total_elements = target_bytes / element_size;

    // Ensure total_elements is multiple of 8 for safe loop execution
    total_elements = (total_elements / 8) * 8;

    data_buffer = (int16_t*)aligned_alloc(32, total_elements * element_size);
    if (!data_buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero values for meaningful computation
    for (size_t idx = 0; idx < total_elements; ++idx) {
        data_buffer[idx] = (int16_t)(idx % 32767);
    }

    ptr = data_buffer;
    i = 0;
}

// Cleanup function to avoid memory leaks (not required but good practice)
void free_vars() {
    if (data_buffer) {
        free(data_buffer);
        data_buffer = NULL;
    }
}