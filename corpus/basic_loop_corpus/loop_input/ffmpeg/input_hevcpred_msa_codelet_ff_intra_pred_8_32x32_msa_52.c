#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
uint8_t *left;
int bottom_left_size;
uint32_t pix;

void init_vars() {
    bottom_left_size = 8;
    pix = 0xDEADBEEF;
    size_t total_size = 1 << 20;
    left = (uint8_t *)aligned_alloc(64, total_size);
    if (!left) {
        exit(1);
    }
}