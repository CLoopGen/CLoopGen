#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

uint8_t *header;
int size;
int x;
uint32_t sum;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec on modern CPU
    header = (uint8_t *)aligned_alloc(4, size);
    if (!header) {
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        header[i] = rand() % 256;
    }
    x = 0;
    sum = 0;
}