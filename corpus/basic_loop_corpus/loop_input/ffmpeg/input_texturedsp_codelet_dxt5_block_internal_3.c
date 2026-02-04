#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *dst;
ptrdiff_t stride;
int x;
int y;
uint32_t colors[4];
uint8_t alpha_indices[16];
uint32_t code;
uint8_t alpha0;
uint8_t alpha1;

static uint8_t *allocated_memory = NULL;

void init_vars() {
    const size_t total_data_size = 1 << 20; // ~1MB of data
    allocated_memory = (uint8_t *)calloc(total_data_size, 1);
    if (!allocated_memory) exit(1);

    dst = allocated_memory;
    stride = 16; // 4 pixels per row * 4 bytes per pixel

    for (int i = 0; i < 4; i++) {
        colors[i] = 0xABCDEF00 + (i * 0x112233);
    }

    for (int i = 0; i < 16; i++) {
        alpha_indices[i] = i % 8;
    }

    code = 0xAAAAAAAA;
    alpha0 = 200;
    alpha1 = 100;

    x = 0;
    y = 0;
}