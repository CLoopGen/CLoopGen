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
    const size_t data_size = 256 * 1024 * 1024; // ~256MB total allocation target
    size_t num_pix_elements = data_size / (sizeof(uint16_t) + sizeof(int32_t)) / 2;
    if (num_pix_elements == 0) num_pix_elements = 1;

    pix_data = (uint16_t*)aligned_alloc(64, num_pix_elements * sizeof(uint16_t));
    block_data = (int32_t*)aligned_alloc(64, num_pix_elements * 4 * sizeof(int32_t));

    for (size_t idx = 0; idx < num_pix_elements; idx++) {
        pix_data[idx] = (uint16_t)(idx & 0xFFFF);
    }
    for (size_t idx = 0; idx < num_pix_elements * 4; idx++) {
        block_data[idx] = (int32_t)(idx * 7);
    }

    stride = 4;
    pix = pix_data;
    block = block_data;
}