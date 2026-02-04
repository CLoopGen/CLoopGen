#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size;
uint8_t *left;
uint32_t pix;

void init_vars() {
    size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    left = (uint8_t *)aligned_alloc(4, size);
    if (!left) {
        exit(1);
    }
    pix = 0xDEADBEEF;
    i = 0;
}