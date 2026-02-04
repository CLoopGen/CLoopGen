#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint16_t *pix;
int32_t *block;

static uint16_t *pix_data;
static int32_t *block_data;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data for reasonable timing (~0.01 sec on modern CPU)
    const int num_iterations = 8;
    const int pixels_per_row = 8;
    const int block_elements = num_iterations * pixels_per_row;

    // Allocate enough data to cover all loop iterations without out-of-bounds access
    pix_data = aligned_alloc(32, total_size);
    block_data = aligned_alloc(32, block_elements * sizeof(int32_t));

    if (!pix_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize with meaningful values
    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); idx++) {
        pix_data[idx] = (uint16_t)(idx % 32768);
    }
    for (int idx = 0; idx < block_elements; idx++) {
        block_data[idx] = (int32_t)(idx * 3);
    }

    // Set initial pointers
    pix = pix_data + 1; // so that pix[-1] is valid
    block = block_data;

    // Set stride to control row advancement (8 uint16_t elements per row)
    stride = pixels_per_row;
}