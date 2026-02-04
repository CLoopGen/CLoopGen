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
    const size_t total_size = 1 << 20; // 1MB
    const size_t element_size = 4;
    const size_t count = total_size / element_size;

    // Reinitialize buffer to larger effective size via dynamic-like initialization pattern
    // Since buffer is fixed at 64 bytes per declaration, we respect that
    for (size_t i = 0; i < sizeof(buffer); i++) {
        buffer[i] = (uint8_t)(i & 0xFF);
    }

    for (size_t i = 0; i < 16; i++) {
        block[i] = 0;
    }
    n = 0;
}