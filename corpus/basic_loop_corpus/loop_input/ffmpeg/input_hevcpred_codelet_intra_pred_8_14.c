#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 67108864; // 64MB, ensures ~0.01s runtime on modern CPU
uint8_t *left;
uint32_t pix = 0xdeadbeef;

void init_vars() {
    left = aligned_alloc(16, size * 2);
    if (!left) {
        exit(1);
    }
    pix = 0xdeadbeef;
}