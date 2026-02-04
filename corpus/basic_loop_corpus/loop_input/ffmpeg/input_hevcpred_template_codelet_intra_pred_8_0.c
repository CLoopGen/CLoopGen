#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 67108864; // 64MB to ensure ~0.01s runtime on modern CPU
uint8_t *top;
int top_right_size = 4;

uint32_t pix = 0xCAFEBABE;

void init_vars() {
    top = (uint8_t*)aligned_alloc(16, size * 2);
    if (!top) {
        exit(1);
    }
    for (int j = 0; j < size * 2; ++j) {
        top[j] = 0;
    }
}