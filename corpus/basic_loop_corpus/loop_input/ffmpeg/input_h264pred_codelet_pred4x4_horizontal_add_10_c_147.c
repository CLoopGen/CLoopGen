#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
uint16_t *pix;
int32_t *block;

static uint16_t *pix_buffer;
static int32_t *block_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of working data
    pix_buffer = aligned_alloc(64, data_size);
    block_buffer = aligned_alloc(64, data_size);

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); idx++) {
        pix_buffer[idx] = (uint16_t)(idx % 30000);
    }
    for (size_t idx = 0; idx < data_size / sizeof(int32_t); idx++) {
        block_buffer[idx] = (int32_t)(idx % 20000);
    }

    pix = pix_buffer + 1; // Ensure pix[-1] is valid
    block = block_buffer;
    stride = 256 / sizeof(uint16_t); // Stride over 256 bytes per row
}