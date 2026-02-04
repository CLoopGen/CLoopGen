#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 67108864; // 64MB to target ~0.01s runtime on modern CPU
uint8_t *left;
int bottom_left_size = 0;
uint32_t pix = 0xCAFEBABE;

void init_vars() {
    left = (uint8_t*)aligned_alloc(16, size * 2);
    if (!left) {
        exit(1);
    }
    bottom_left_size = 0;
    pix = 0xCAFEBABE;
}