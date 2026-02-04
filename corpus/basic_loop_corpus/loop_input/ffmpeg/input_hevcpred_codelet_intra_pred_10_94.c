#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int i;
int size = 65536;
int bottom_left_size = 1024;
uint16_t *left;
uint64_t pix = 0xCAFEBABEDEADBEEFULL;

void init_vars() {
    left = aligned_alloc(64, (size + bottom_left_size + size) * sizeof(uint16_t));
    if (!left) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}