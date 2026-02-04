#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};

int i;
int size = 65536; // Ensures 2 * size = 131072, and loop processes 4 bytes per iteration
uint8_t *left;
uint32_t pix = 0xdeadbeef;

void init_vars() {
    left = aligned_alloc(4, 2 * size);
    if (!left) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}