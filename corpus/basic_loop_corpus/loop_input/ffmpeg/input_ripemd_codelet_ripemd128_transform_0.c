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
    for (int i = 0; i < 64; i++) {
        buffer[i] = (uint8_t)(i * i + 3 * i + 42);
    }
    for (int i = 0; i < 16; i++) {
        block[i] = 0;
    }
    n = 0;
}