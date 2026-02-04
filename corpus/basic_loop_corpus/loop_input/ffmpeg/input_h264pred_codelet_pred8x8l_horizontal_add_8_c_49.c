#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride;
int i;
uint8_t *pix;
int16_t *block;

uint8_t *pix_data;
int16_t *block_data;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    const int num_iterations = 8;
    const int pixels_per_row = 8;
    const int block_elements_per_iter = 8;

    stride = 64; // chosen to avoid overlap and allow alignment

    pix_data = (uint8_t*)aligned_alloc(64, total_size);
    block_data = (int16_t*)aligned_alloc(64, num_iterations * block_elements_per_iter * sizeof(int16_t));

    if (!pix_data || !block_data) {
        abort();
    }

    for (size_t i = 0; i < total_size; i++) {
        pix_data[i] = rand() & 0xFF;
    }
    for (int i = 0; i < num_iterations * block_elements_per_iter; i++) {
        block_data[i] = (rand() % 512) - 256;
    }

    pix = pix_data + 1; // so that pix[-1] is valid
    block = block_data;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}