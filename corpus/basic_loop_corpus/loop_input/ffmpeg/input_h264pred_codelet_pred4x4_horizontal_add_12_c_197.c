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
    const size_t total_size = 1 << 20; // 1MB of data for ~0.01 sec runtime estimate
    const size_t num_pixels = total_size / sizeof(uint16_t) / 4; // 4 rows accessed

    stride = 1024; // Large enough to avoid overlap, typical cache-conscious stride

    // Allocate aligned memory to prevent issues and improve performance
    pix_data = aligned_alloc(64, (num_pixels + 1) * sizeof(uint16_t));
    block_data = aligned_alloc(64, num_pixels * 4 * sizeof(int32_t));

    if (!pix_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize pix_data: leave pix[-1] valid, so base pointer starts at offset 1
    for (size_t idx = 0; idx < num_pixels + 1; ++idx) {
        pix_data[idx] = (uint16_t)(idx & 0xFFFF);
    }

    for (size_t idx = 0; idx < num_pixels * 4; ++idx) {
        block_data[idx] = (int32_t)(idx % 1000);
    }

    pix = pix_data + 1; // So that pix[-1] is within allocated bounds
    block = block_data;
}