#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

#define BLOCK_SIZE (1 << 17)  // Adjust to control runtime (~128KB for block, ~256KB total)
#define SRC_SIZE (BLOCK_SIZE * 8)

static uint16_t src_data[SRC_SIZE];
static int32_t block_data[BLOCK_SIZE];

void init_vars() {
    // Initialize pix array with non-zero values
    for (int j = 0; j < 8; j++) {
        pix[j] = (uint16_t)(j + 1) * 100;
    }

    // Initialize block data with sequential values
    for (int j = 0; j < BLOCK_SIZE; j++) {
        block_data[j] = (int32_t)(j % 1000);
    }

    // Set src and block pointers to the beginning of our data
    src = src_data;
    block = block_data;

    // Set stride to 8 for consistent advancement
    stride = 8;

    // Initialize i to 0 (will be set by loop but ensure valid state)
    i = 0;
}