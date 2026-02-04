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
    const size_t total_pixels = 1 << 20; // ~2MB of uint16_t data
    const int height = 1 << 18; // Sufficient rows to run loop many times

    stride = (ptrdiff_t)(1 << 10); // Stride of 1024 elements per row

    pix_buffer = calloc(total_pixels, sizeof(uint16_t));
    block_buffer = malloc(total_pixels * 4 * sizeof(int32_t));

    if (!pix_buffer || !block_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_pixels; ++idx) {
        pix_buffer[idx] = (uint16_t)(idx % 3000);
    }
    for (size_t idx = 0; idx < total_pixels * 4; ++idx) {
        block_buffer[idx] = (int32_t)(idx % 5000 - 2500);
    }

    pix = pix_buffer + 1; // Ensure pix[-1] is valid
    block = block_buffer;
}