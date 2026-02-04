#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 16;
int i;
uint16_t *pix;
int32_t *block;

static uint16_t pix_data[256 * 1024 * 1024 / sizeof(uint16_t)]; // ~256MB of data
static int32_t block_data[16 * 1024 * 1024 / sizeof(int32_t)]; // ~64MB of data

void init_vars() {
    if (pix_data == NULL || block_data == NULL) {
        exit(1);
    }

    pix = pix_data;
    block = block_data;

    for (size_t j = 0; j < sizeof(pix_data)/sizeof(pix_data[0]); j++) {
        pix_data[j] = (uint16_t)(j & 0xFFFF);
    }
    for (size_t j = 0; j < sizeof(block_data)/sizeof(block_data[0]); j++) {
        block_data[j] = (int32_t)(j * 7);
    }
}