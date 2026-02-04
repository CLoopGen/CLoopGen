#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
uint8_t *src;
int16_t *block;
uint8_t pix[8];
int stride;

static uint8_t src_data[1 << 20]; // 1MB
static int16_t block_data[64];

void init_vars() {
    src = src_data;
    block = block_data;
    stride = 64; // reasonable stride to prevent overlap and bound issues

    for (int j = 0; j < 8; j++) {
        pix[j] = (uint8_t)(j + 1);
    }

    for (int j = 0; j < 64; j++) {
        block_data[j] = (int16_t)(j - 32);
    }
}