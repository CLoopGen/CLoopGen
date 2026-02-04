#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i;
uint8_t *src;
int16_t *block;
uint8_t pix[8];
int stride;

static uint8_t src_data[1 << 20]; // ~1MB for src
static int16_t block_data[8 * (1 << 20) / 8]; // enough for 8 * (iterations), assuming each iteration uses 8 elements

void init_vars() {
    // Initialize pix with non-zero values
    for (int j = 0; j < 8; j++) {
        pix[j] = (uint8_t)(j + 1) * 17;
    }

    // Set stride to a reasonable value, e.g., 16 or 32
    stride = 32;

    // Initialize src to point inside src_data with room to advance by stride up to ~32k iterations
    src = src_data;
    
    // Initialize block to point to block_data
    block = block_data;

    // Fill block_data with some representative values to avoid undefined behavior during accumulation
    size_t num_block_elements = sizeof(block_data) / sizeof(int16_t);
    for (size_t idx = 0; idx < num_block_elements; idx++) {
        block_data[idx] = (int16_t)((idx % 16) - 8);
    }
}