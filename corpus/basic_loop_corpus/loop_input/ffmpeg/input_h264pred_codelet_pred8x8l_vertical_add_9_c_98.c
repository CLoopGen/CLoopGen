#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 16;
int i;
uint16_t *pix;
int32_t *block;

static uint16_t pix_data[256 * 1024 * 1024 / sizeof(uint16_t)]; // ~256MB of uint16_t
static int32_t block_data[64];

void init_vars() {
    stride = 16;
    pix = pix_data;
    block = block_data;

    for (int idx = 0; idx < 64; idx++) {
        block_data[idx] = idx * 100;
    }

    for (int idx = 0; idx < 256 * 1024 * 1024 / sizeof(uint16_t); idx++) {
        pix_data[idx] = idx % 30000;
    }
}