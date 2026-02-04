#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t keybits[32];
uint8_t *buf;
uint32_t key;

void init_vars() {
    // Allocate 64MB for buf to ensure loop runtime around 0.01s on modern CPU
    size_t buf_size = 64 << 20; // 64 * 2^20 = 67,108,864 bytes
    buf = (uint8_t*)calloc(buf_size, sizeof(uint8_t));
    if (!buf) {
        exit(1);
    }

    // Initialize keybits so that all indices are within buf bounds
    for (int i = 0; i < 32; i++) {
        keybits[i] = (uint8_t)(i * 2000000); // Spread across buffer, well within 64MB
    }

    // Initialize key to 0
    key = 0;
}