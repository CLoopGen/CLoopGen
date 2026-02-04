#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

static uint16_t src_data[256 * 1024 * 1024 / sizeof(uint16_t)]; // ~256MB for src
static int32_t block_data[256 * 1024 * 1024 / sizeof(int32_t)]; // ~256MB for block

void init_vars() {
    stride = 16; 

    for (int j = 0; j < 8; ++j) {
        pix[j] = (uint16_t)(j + 1) * 100;
    }

    src = src_data;
    block = block_data;

    for (size_t k = 0; k < sizeof(src_data)/sizeof(src_data[0]); ++k) {
        src_data[k] = (uint16_t)(k % 65535);
    }
    for (size_t k = 0; k < sizeof(block_data)/sizeof(block_data[0]); ++k) {
        block_data[k] = (int32_t)(k % 1000) - 500;
    }
}