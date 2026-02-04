#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical modern CPU
uint8_t *left;
uint32_t pix = 0xdeadbeef;

void init_vars() {
    left = aligned_alloc(16, size);
    if (!left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}