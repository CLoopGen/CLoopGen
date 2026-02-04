#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

void **pt;
void *tt[8];
int i;

static void *data_pool;
static void **ptr_array;

void init_vars() {
    // Allocate a large data pool to ensure measurable runtime
    // Use 64MB of pointer storage to create significant memory traffic
    const size_t num_ptrs = 64 * (1 << 20) / sizeof(void*); // ~64M / ptr_size
    data_pool = calloc(num_ptrs, sizeof(void*));
    if (!data_pool) return;

    ptr_array = malloc(8 * sizeof(void*));
    if (!ptr_array) {
        free(data_pool);
        return;
    }

    // Initialize each of the 8 pointers in ptr_array to point into data_pool
    for (int j = 0; j < 8; j++) {
        ptr_array[j] = (char*)data_pool + (j * (num_ptrs / 8) * sizeof(void*));
    }

    // Assign pt to point to our allocated array of 8 pointers
    pt = ptr_array;

    // Zero-initialize tt array (will be overwritten in loop)
    for (int j = 0; j < 8; j++) {
        tt[j] = NULL;
    }

    // Ensure i is initialized to 0 before loop starts (done in loop itself)
}

// Explicitly prevent main from being defined here