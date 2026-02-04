#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t buffer[64] = {0};
uint32_t block[16] = {0};
int n = 0;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB
    static uint8_t large_buffer[1 << 20];
    static uint32_t large_block[1 << 18];

    for (size_t i = 0; i < data_size; i++) {
        large_buffer[i] = (uint8_t)(i & 0xFF);
    }

    for (int i = 0; i < 16; i++) {
        ((uint8_t*)large_buffer)[4 * i + 0] = (uint8_t)(0x11 + i);
        ((uint8_t*)large_buffer)[4 * i + 1] = (uint8_t)(0x22 + i);
        ((uint8_t*)large_buffer)[4 * i + 2] = (uint8_t)(0x33 + i);
        ((uint8_t*)large_buffer)[4 * i + 3] = (uint8_t)(0x44 + i);
    }

    for (size_t i = 0; i < 64; i++) {
        buffer[i] = large_buffer[i % data_size];
    }

    n = 0;
}