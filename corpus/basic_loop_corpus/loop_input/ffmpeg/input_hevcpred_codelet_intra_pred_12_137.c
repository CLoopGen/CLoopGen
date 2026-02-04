#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = (1 << 20); // 1MB of data
int bottom_left_size = 64;
uint16_t *left;
uint64_t pix = 0xCAFEBABECAFEBABEULL;

void init_vars() {
    left = aligned_alloc(64, sizeof(uint16_t) * (size + bottom_left_size + size));
    if (!left) {
        exit(1);
    }
}