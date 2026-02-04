#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint16_t *pix;
int32_t *block;

uint16_t *pix_data;
int32_t *block_data;

void init_vars() {
    // Allocate approximately 128MB of total data to achieve ~0.01s runtime on modern CPUs
    // Use large arrays to allow compiler optimization evaluation with realistic memory behavior
    
    const size_t pix_size = 16 * 1024 * 1024; // ~32 MB for pix_data (16M elements * 2 bytes)
    const size_t block_size = 16 * 1024 * 1024; // ~64 MB for block_data (16M elements * 4 bytes)
    
    pix_data = (uint16_t*)aligned_alloc(64, pix_size * sizeof(uint16_t));
    block_data = (int32_t*)aligned_alloc(64, block_size * sizeof(int32_t));

    if (!pix_data || !block_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize data to avoid undefined behavior
    for (size_t idx = 0; idx < pix_size; idx++) {
        pix_data[idx] = (uint16_t)(idx % 30000);
    }
    for (size_t idx = 0; idx < block_size; idx++) {
        block_data[idx] = (int32_t)(idx % 20000 - 10000);
    }

    // Set global pointers
    pix = pix_data;
    block = block_data;

    // Ensure stride is reasonable for memory access: at least 4*stride fits in allocated space
    stride = 1024; // Large enough to avoid overlap, small enough to stay in bounds

    // Reset loop counter
    i = 0;
}