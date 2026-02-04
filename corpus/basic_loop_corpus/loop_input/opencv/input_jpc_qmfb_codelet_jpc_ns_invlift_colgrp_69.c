#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

typedef int_fast32_t jpc_fix_t;
typedef int_fast64_t jpc_fix_big_t;

jpc_fix_t *hptr2;
int i;

static jpc_fix_t *hptr2_storage;

void init_vars() {
    // Allocate a buffer large enough to support multiple runs of the loop (16 iterations, each incrementing hptr2)
    // We allocate 256MB of data to ensure significant runtime (~0.01s or more on modern CPU)
    const size_t total_size = 256 * 1024 * 1024;
    const size_t elem_size = sizeof(jpc_fix_t);
    const size_t num_elements = total_size / elem_size;

    // Allocate and initialize storage
    hptr2_storage = (jpc_fix_t*)aligned_alloc(64, total_size);
    if (!hptr2_storage) {
        exit(1);
    }

    // Initialize all elements to non-zero to simulate realistic data
    for (size_t idx = 0; idx < num_elements; ++idx) {
        hptr2_storage[idx] = (jpc_fix_t)(idx * 7 + 1);
    }

    // Initialize hptr2 to point at the beginning of the buffer
    hptr2 = hptr2_storage;
}

// Cleanup function to avoid memory leaks (not required by problem, but good practice)
void cleanup_vars() {
    if (hptr2_storage) {
        free(hptr2_storage);
        hptr2_storage = NULL;
    }
}