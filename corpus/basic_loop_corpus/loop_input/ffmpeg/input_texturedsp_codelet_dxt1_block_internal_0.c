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
uint32_t code;

void init_vars() {
    const size_t total_data_size = 16 * 1024 * 1024; // ~16 MB for sustained loop execution (~0.01 sec on modern CPU)
    dst = (uint8_t*)aligned_alloc(16, total_data_size);
    if (!dst) exit(1);

    stride = 4 * 4; // 4 pixels per row, each 4 bytes

    colors[0] = 0xFF0000FF;
    colors[1] = 0x00FF00FF;
    colors[2] = 0x0000FFFF;
    colors[3] = 0xFFFF00FF;

    code = 0xDEADBEEF;

    x = 0;
    y = 0;
}