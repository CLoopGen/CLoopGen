#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

#define DATA_SIZE (1 << 20)  // 1MB of input data

static uint16_t src_data[DATA_SIZE / sizeof(uint16_t)];
static int32_t block_data[DATA_SIZE / sizeof(int32_t)];

void init_vars() {
    // Initialize pix with sample values
    for (int j = 0; j < 8; j++) {
        pix[j] = (uint16_t)(j * 100);
    }

    // Initialize block_data with non-zero values to ensure meaningful computation
    for (size_t k = 0; k < DATA_SIZE / sizeof(int32_t); k++) {
        block_data[k] = (int32_t)(k % 500);
    }

    // Set stride to 8 (common in block-based image processing)
    stride = 8;

    // Initialize src and block pointers to point into the large arrays
    src = src_data;
    block = block_data;

    // Ensure that we have enough space so the loop does not go out of bounds
    // The loop runs 8 times, each time accessing src[0..7] and block[0..7]
    // And increments src by stride and block by 8 each iteration
    // So total required:
    //   src: 8 rows * stride apart, each row needs 8 elements -> 8 * stride >= 64
    //   block: 8 * 8 = 64 elements
    //
    // Our DATA_SIZE is much larger than needed, so safe.
}