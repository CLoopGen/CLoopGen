#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
uint8_t *left;
int size_max_y;
uint32_t pix;

void init_vars() {
    size_max_y = 64 * 1024 * 1024; // 64MB to target ~0.01 sec runtime
    left = (uint8_t *)aligned_alloc(4, size_max_y);
    if (!left) {
        exit(1);
    }
    pix = 0xdeadbeef;
    for (int j = 0; j < size_max_y; j++) {
        left[j] = 0;
    }
}