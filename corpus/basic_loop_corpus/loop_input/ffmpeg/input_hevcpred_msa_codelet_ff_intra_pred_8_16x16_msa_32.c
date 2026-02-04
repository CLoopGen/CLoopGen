#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
ptrdiff_t stride = 16;
uint8_t *src;
uint8_t *left;

static uint8_t src_data[256 * 1024 * 1024]; // 256 MB to ensure ~0.01s runtime
static uint8_t left_data[16];

void init_vars() {
    for (int j = 0; j < 256 * 1024 * 1024; j++) {
        src_data[j] = (uint8_t)(j & 0xFF);
    }
    src = src_data + 1; // Adjust so that accessing index -1 is valid
    left = left_data;
}