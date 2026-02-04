#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 65536;
uint16_t *left;
int bottom_left_size = 1024;

uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    left = (uint16_t*)aligned_alloc(8, sizeof(uint16_t) * (size + bottom_left_size + size));
    if (!left) {
        exit(1);
    }
}