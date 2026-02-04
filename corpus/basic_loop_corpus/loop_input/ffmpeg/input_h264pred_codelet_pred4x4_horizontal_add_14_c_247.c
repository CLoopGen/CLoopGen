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
    const size_t total_size = 1 << 20; // 1MB working set
    const size_t num_blocks = total_size / (4 * sizeof(int32_t)) / 4; // 4 rows of 4 elements each per loop iteration

    stride = 1; 

    pix_data = aligned_alloc(64, (num_blocks + 1) * stride * sizeof(uint16_t));
    block_data = aligned_alloc(64, num_blocks * 4 * sizeof(int32_t));

    if (!pix_data || !block_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    pix = pix_data + 1; 
    block = block_data;

    for (size_t idx = 0; idx < num_blocks; ++idx) {
        pix_data[idx * stride] = (uint16_t)(idx & 0xFFFF);
        for (int k = 0; k < 4; ++k) {
            block_data[idx * 4 + k] = (int32_t)(idx * 4 + k);
        }
    }
}