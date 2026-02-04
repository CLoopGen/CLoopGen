#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *top;
uint8_t *filtered_top;

static uint8_t *top_storage;
static uint8_t *filtered_top_storage;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    top_storage = (uint8_t *)aligned_alloc(32, data_size);
    filtered_top_storage = (uint8_t *)aligned_alloc(32, data_size);

    if (!top_storage || !filtered_top_storage) {
        exit(1);
    }

    top = top_storage + 1; // Adjust so that top[i-1] at i=0 accesses valid memory
    filtered_top = filtered_top_storage + 1;

    for (size_t idx = 0; idx < data_size; idx++) {
        top_storage[idx] = rand() % 256;
    }

    // Ensure boundaries for the loop: i goes down to 0, and we access i+1, i, i-1
    // So we need valid data from index 0 to data_size - 2 in top (after adjustment)
}

// Cleanup function to free allocated memory (if needed in full program)
void cleanup_vars() {
    if (top_storage) free(top_storage);
    if (filtered_top_storage) free(filtered_top_storage);
}