#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime

static uint16_t src_data[DATA_SIZE] = {0};
static int32_t block_data[DATA_SIZE] = {0};

void init_vars() {
    // Initialize pix array
    for (int j = 0; j < 8; j++) {
        pix[j] = (uint16_t)(j * 100 + 1);
    }

    // Set stride to 16 to allow safe access with 7*stride offset
    stride = 16;

    // Initialize block data with non-zero values
    for (int j = 0; j < DATA_SIZE; j++) {
        block_data[j] = (int32_t)(j % 500);
    }

    // Initialize source data
    for (int j = 0; j < DATA_SIZE; j++) {
        src_data[j] = (uint16_t)(j % 1000);
    }

    // Assign pointers to beginning of data arrays
    src = src_data;
    block = block_data;
}