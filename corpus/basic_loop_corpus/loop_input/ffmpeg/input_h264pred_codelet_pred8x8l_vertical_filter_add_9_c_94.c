#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

static uint16_t src_data[1024 * 1024 / sizeof(uint16_t)];     // ~1MB for src
static int32_t block_data[1024 * 1024 / sizeof(int32_t)];   // ~1MB for block

void init_vars() {
    stride = 64;  // reasonable alignment stride, ensures no overlap in rows

    // Initialize pix with non-zero values
    for (int j = 0; j < 8; j++) {
        pix[j] = (j + 1) * 10;
    }

    // Align data pointers to start of static arrays
    src = src_data;
    block = block_data;

    // Initialize block_data with sequential values to avoid undefined behavior during accumulation
    for (int j = 0; j < 1024 * 1024 / sizeof(int32_t); j++) {
        block_data[j] = (j % 64) * 5;
    }
}