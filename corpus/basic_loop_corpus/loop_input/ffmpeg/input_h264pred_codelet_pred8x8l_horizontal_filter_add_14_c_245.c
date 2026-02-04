#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint16_t *src;
int32_t *block;
uint16_t pix[8];
int stride;

static uint16_t src_buffer[1024 * 1024 / sizeof(uint16_t)]; // ~1MB buffer
static int32_t block_buffer[8 * 1024]; // 8 elements per block, up to 1024 blocks

void init_vars() {
    stride = 8;
    for (int j = 0; j < 8; j++) {
        pix[j] = (uint16_t)(j + 1) * 10;
    }

    src = src_buffer;
    block = block_buffer;

    for (int j = 0; j < 8 * 1024; j++) {
        block_buffer[j] = (int32_t)(j % 256) - 128;
    }
}