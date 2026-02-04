#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 64;

int i;

uint8_t *pix;
int16_t *block;

static uint8_t pix_data[64 * 64];
static int16_t block_data[64];

void init_vars() {
    pix = pix_data;
    block = block_data;
}