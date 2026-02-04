#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
ptrdiff_t stride = 1024;
uint8_t *src;
uint8_t *left;

static uint8_t src_data[1 << 20]; // 1MB
static uint8_t left_data[32];

void init_vars() {
    for (int j = 0; j < (1 << 20); j++) {
        src_data[j] = (uint8_t)(j & 0xFF);
    }
    for (int j = 0; j < 32; j++) {
        left_data[j] = 0;
    }
    src = src_data;
    left = left_data;
    i = 0;
}