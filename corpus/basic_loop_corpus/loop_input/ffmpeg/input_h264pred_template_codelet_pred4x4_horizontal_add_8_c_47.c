#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int i;
uint8_t *pix;
int16_t *block;

uint8_t *pix_base;
int16_t *block_base;
size_t data_size;

void init_vars() {
    // Aim for approximately 0.01 seconds runtime
    // The loop runs 4 iterations, each accessing 4 pixels and 4 block elements
    // We'll replicate the inner loop pattern across a larger dataset to achieve desired runtime
    // Each iteration advances pix by stride and block by 4
    // To avoid out-of-bounds, ensure sufficient padding before pix and after block

    data_size = (1 << 20); // ~1MB of working data as baseline

    // Allocate pix with padding: we access pix[-1], so need at least 1 byte before start
    pix_base = aligned_alloc(32, data_size + 32);
    if (!pix_base) exit(1);
    pix = pix_base + 1; // so pix[-1] is valid

    // Allocate block: 4 elements per loop iteration, 4 iterations -> 16 elements total
    block_base = aligned_alloc(32, 16 * sizeof(int16_t));
    if (!block_base) exit(1);
    block = block_base;

    // Set stride to something reasonable - say, 16 bytes per row
    stride = 16;

    // Initialize all data to non-zero to avoid accidental optimizations
    for (size_t j = 0; j < data_size + 31; j++) {
        pix_base[j] = (uint8_t)(j % 251);
    }
    for (int j = 0; j < 16; j++) {
        block_base[j] = (int16_t)(j + 1);
    }

    // Initialize loop counter
    i = 0;
}