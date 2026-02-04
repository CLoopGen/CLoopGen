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
    for (int j = 0; j < 64; j++) {
        block_data[j] = j * 37; // arbitrary initialization
    }
    for (size_t k = 0; k < sizeof(pix_data)/sizeof(pix_data[0]); k++) {
        pix_data[k] = k * 17; // arbitrary initialization
    }
    pix = pix_data;
    block = block_data;
}