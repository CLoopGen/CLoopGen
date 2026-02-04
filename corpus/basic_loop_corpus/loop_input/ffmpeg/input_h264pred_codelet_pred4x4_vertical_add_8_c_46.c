#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 64;
int i;
uint8_t *pix;
int16_t *block;

static uint8_t pix_data[256 * 1024 * 1024]; // ~256MB to ensure ~0.01s runtime
static int16_t block_data[16 * 4]; // Enough for 4 iterations, each accessing 4 elements

void init_vars() {
    pix = pix_data;
    block = block_data;
}